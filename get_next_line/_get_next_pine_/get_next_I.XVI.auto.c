#include "stdlib.h"
#include "unistd.h"
#ifndef	BU
#define BU 32
#endif
#define null NULL

char	*get_bloc(int, char *);
char	*gen_bloc(char *, char *);
char	*get_line(char *);
char	*new_bloc(char *);
int	Len(char *);
char	*Sch(char *);

char	*get_next_line(int fd)
{
	static char	*bloc;
	char		*line;

	if (fd < 0 || BU < 1)
		return null ;
	bloc = get_bloc(fd, bloc);
	if (!bloc)
		return null ;
	line = get_line(bloc);
	bloc = new_bloc(bloc);
	return line ;
}

char	*get_bloc(int fd, char *bloc){
	char	buff[BU + 1];
	int	bytes = 1;
	while (bytes && !Sch(bloc)) {
		bytes = read(fd, buff, BU);
		if (bytes == -1)
			return null ;
		buff[bytes] = 0;
		bloc = gen_bloc(bloc, buff);
	}
	return bloc ;
}

char	*gen_bloc(char *bloc, char *buff){
	char	*rest;
	int	size, i, j;
	if (!bloc)
	{
		bloc = (char *) malloc(sizeof(char));
		if (!bloc)
			return null ;
		bloc[0] = 0;
	}
	size = Len(bloc) + Len(buff);
	rest = (char *) malloc(sizeof(char) * (size + 1));
	i = -1;
	while (bloc[++i])	rest[i] = bloc[i];
	j = 0;
	while (buff[j])	rest[i++] = buff[j++];// XXX
	rest[i] = 0;
	free(bloc);
	return rest ;
}

char	*get_line(char *bloc) {
	char	*line;
	int	i;
	if (!Len(bloc))	return null ;
	i = 0;
	while (bloc[i] && bloc[i] != 10)	i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	i = -1;
	while (bloc[++i] && bloc[i] != 10)	line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)	line[i] = bloc[i];
	//if (bloc[i] && bloc[i] == 10)	line[i] = 10;
	line[++i] = 0;
	return line ;
}

char	*new_bloc(char *bloc){
	char	*rest;
	int	size, i, j;
	i = 0;
	while (bloc[i] && bloc[i] != 10)	i++;
	//if (bloc[i])
	if (!bloc[i])
	{
		free(bloc);
		return null ;
	}
	size = Len(bloc) - i;
	rest = (char *) malloc(sizeof(char) * (size + 1));
	i += 1;
	j = 0;
	while (bloc[i])	rest[j++] = bloc[i++];
	rest[j] = 0;
	free(bloc);
	return rest ;
}

char	*Sch(char *s)
{
	if (!s)	return 0 ;
	int	i = -1;
	while (s[++i])
		if (s[i] == 10)
			return ((char *) &s[i]);
	return 0 ;
}

int	Len(char *s)
{
	if (!s)	return 0 ;
	int	i = 0;
	while (s[i])	i++;
	return i ;
}



#include "fcntl.h"
#include "stdio.h"
#define	ss printf("---\n")
#define end printf("\n")

int	main()
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
