#include "unistd.h"
#include "stdlib.h"
#ifndef BU
#define BU 32
#endif

char	*get_next_line(int);
char	*get_bloc(int, char *);
char	*gen_bloc(char *, char *);
char	*get_line(char *);
char	*new_bloc(char *);
char	*sc(int, char *);
int	len(char *);

char	*get_next_line(int fd)
{
	if (fd < 0)	return NULL ;
	if (BU < 1)	return NULL ;
	static char	*bloc;
	char		*line;
	bloc = get_bloc(fd, bloc);
	if (!bloc)	return NULL ;
	line = get_line(bloc);
	bloc = new_bloc(bloc);
	return line ;
}

char	*get_bloc(int fd, char *bloc)
{
	// first function, don't check bloc, malloc the buff immediately
	// we also need to keep track of the bytes read
	char	*buff;
	buff = (char *) malloc(sizeof(char) * (BU + 1));
	int	R = 1;
	while (R && !sc(10, bloc))
	{
		R = read(fd, buff, BU);
		if (R < 0)
		{
			free(buff);
			return NULL ;
		}
		// REMEMBER TO SEAL IT
		buff[R] = 0;
		bloc = gen_bloc(bloc, buff);
	}
	free(buff);
	return bloc ;
}

char	*gen_bloc(char *bloc, char *buff)
{
	// sub function of the first function --> append buff to bloc

	// check buff
	// check not bloc, but len(bloc), cause a static is always at least size one
	if (!buff)	return NULL ;
	if (!len(bloc))	bloc = (char *) malloc(sizeof(char)), bloc[0] = 0;

	// we need 2 pointers, one for strcpy, one for strcat
	char	*res;
	int	size, i, j;
	size = len(bloc) + len(buff);
	res = (char *) malloc(sizeof(char) * (size + 1));
	i = -1;
	while (bloc[++i])	res[i] = bloc[i];
	j = 0;
	while (buff[j])		res[i++] = buff[j++];

	// REMEMBER TO SEAL IT
	res[size] = 0;

	// we don't free buff otherwise double free
	// we free bloc cause we don't need bloc anymore, we have res
	free(bloc);
	return res ;
}

char	*get_line(char *bloc)
{
	// second function, extract the line
	// bloc is static, static is always at least a nul char
	// so, check len(bloc) instead of (bloc)

	if (!len(bloc))	return NULL ;
	int i = 0;
	while (bloc[i] && bloc[i] != 10)	i ++;
	char *line = (char *) malloc(sizeof(char) * (i + 2));
	i = -1;
	while (bloc[++i] && bloc[i] != 10)	line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)		line[i] = bloc[i];
	line[++i] = 0;
	return line ;
}

char	*new_bloc(char *bloc)
{
	// third function, a new bloc is a "cut" / "trimmed" bloc
	// if we stop at the nul, it means this is the last bloc, free bloc, job done
	// if we stop at a newline, trim it, replace the bloc with newly trimmed bloc

	int	i = 0;
	while (bloc[i] && bloc[i] != 10)	i++ ;
	if (!bloc[i])
	{
		free(bloc);
		return NULL ;
	}
	int	size = len(bloc) - i;
	char	*res = (char *) malloc(sizeof(char) * (size + 1));
	i ++ ;
	int	j = 0;
	while (i < size)	res[j++] = bloc[i++];
	res[j] = 0;
	free(bloc);
	return res ;
}

char	*sc(int c, char *s)
{
	//if (!s)	return 0 ;
	if (!s)	return NULL ;
	if (!c)	return ( (char *) &s[len(s)] );
	int	i = -1;
	while (s[++i])	if (c == s[i])	return ( (char *) &s[i] );
	return NULL ;
}

int	len(char *s)
{
	if (!s)	return 0 ;
	int	i = 0;
	while (s[i])	i ++;
	return i ;
}

//	DRIVE

#include "iostream"
#include "fcntl.h"
#include "stdio.h"
#define	ss printf("---\n")
#define fi printf("\n")
int	main(int argc, char *argv[])
{
	char	*L;
	int	i = 0, f = open("texts/MSP", O_RDONLY);
	ss;
	while (++i < 21)
	{
		L = get_next_line(f);
		printf("# %0.2d: %s", i, L);
		if (!L)	fi;
		else	free(L);
	}
	close(f);
	ss;
}
