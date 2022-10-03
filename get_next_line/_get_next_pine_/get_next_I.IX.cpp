/* ******************************************** */
/*                                              */
/*              ~  ~  ~  ~  ~    ~              */
/*               ~    _ ~ _   o>                */
/*              ~  \ / \ / \ /  ~               */
/*               ~  ~      ~    ~               */
/*                                              */
/* ******************************************** */

#include "stdlib.h"
#include "unistd.h"
#ifndef	BU
#define BU 32
#endif
#define null NULL

char	*get_next_line(int);
char	*get_bloc(int, char *);
char	*cop_bloc(char *, char *);
char	*get_line(char *);
char	*new_bloc(char *);
char	*sch(int, char *);
int	len(char *);

char	*get_next_line(int fd)
{
	static char	*bloc;
	if (fd < 0)	return null ;
	if (BU < 1)	return null ;
	char		*line;
	bloc = get_bloc(fd, bloc);
	if (!bloc)	return null ;
	line = get_line(bloc);
	bloc = new_bloc(bloc);
	return line ;
}

char	*get_bloc(int fd, char *bloc) // new version: FREE NO BUFF
{
	//char	*buff = (char *) malloc(sizeof(char) * (BU + 1));
	char	buff[BU + 1];
	int	bytes = 1;
	while (bytes && !sch(10, bloc)) // XXX attention : bloc is the only thing we can deduce
	{
		bytes = read(fd, buff, BU);
		if (bytes == -1)
		{
			//free(buff);
			return null ;
		}
		buff[bytes] = 0;
		bloc = cop_bloc(bloc, buff);
	}
	//free(buff);
	return bloc ;
}

char	*cop_bloc(char *bloc, char *buff)
{
	if (!buff)
		return null ;

	if (!bloc)
		bloc = (char *) malloc(sizeof(char)), bloc[0] = 0 ; // proved equivalent
	//if (!len(bloc))
	//	bloc = (char *) malloc(sizeof(char)), bloc[0] = 0 ;

	char	*rest;
	int	i, j, size;
	size = len(bloc) + len(buff);
	rest = (char *) malloc(sizeof(char) * (size + 1));
	i = -1;
	while (bloc[++i])	rest[i] = bloc[i];
	j = 0;
	while (buff[j])		rest[i++] = buff[j++]; // XXX

	rest[i] = 0; // proved equivalent
	// rest[size] = 0;

	free(bloc);	// XXX
	return rest ;
}

char	*get_line(char *bloc)
{
	if (!len(bloc))	return null ; // proved equivalent as (!(bloc[0]))
	// if (!bloc[0])	... ;

	// if (!bloc)	return null ; // XXX : can't, must check len() or [0]

	int	i = 0;
	while (bloc[i] && bloc[i] != 10)	i ++;
	char	*line = (char *) malloc(sizeof(char) * (i + 2));
	i = -1;
	while (bloc[++i] && bloc[i] != 10)	line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)		line[i] = bloc[i];
	line[++i] = 0;
	return line ;
}

char	*new_bloc(char *bloc)
{
	int	i, j, size;
	i = 0;
	while (bloc[i] && bloc[i] != 10)	i++ ;
	if (!bloc[i])
	{
		free(bloc);
		return null ;
	}
	size = len(bloc) - i;
	char	*rest = (char *) malloc(sizeof(char) + (size + 1));
	i ++;
	j = 0;

	while (bloc[i])	rest[j ++] = bloc[i ++];	// CRUCIAL FIX
	//while (i < size)	rest[j ++] = bloc[i ++]; // XXX

	rest[j] = 0; // proved equivalent
	// rest[size] = 0;

	free(bloc);
	return rest ;
}

char	*sch(int c, char *s)
{
	if (!s)	return 0 ;
	if (!c)	return ((char *) &s[len(s)]);

	int	i = -1;
	while (s[++i])	if (c == s[i])	return ((char *) &s[i]);
	return 0 ;
}

int	len(char *s)
{
	if (!s)	return 0 ;
	int	i = 0;
	while (s[i])	i++ ;
	return i ;
}

//	DRIVE

#include "iostream"
#include "fcntl.h"
#include "stdio.h"
#define	ss printf("---\n")
#define end printf("\n")

int	main(int argc, char *argv[])
{
	char	*L;
	int	i = 0, f = open("texts/MSP", O_RDONLY);
	ss;
	while (++i < 17)
	{
		L = get_next_line(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;

	i = 0;
	f = open("texts/ANM", O_RDONLY);
	while (++i <= 10)
	{
		L = get_next_line(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;

	i = 0;
	f = open("texts/RT", O_RDONLY);
	while (++i <= 12)
	{
		L = get_next_line(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;
}
