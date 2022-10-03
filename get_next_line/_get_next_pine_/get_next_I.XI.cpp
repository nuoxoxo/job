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


char	*getnextline(int);
char	*pullbloc(int, char *);
char	*makebloc(char *, char *);
char	*makeline(char *);
char	*newbloc(char *);
char	*hasnl(char *);
int	len(char *);

char	*getnextline(int fd)
{
	static char	*bloc;
	if (fd < 0)	return null ;
	if (BU < 1)	return null ;
	char		*line;
	bloc = pullbloc(fd, bloc);
	if (!bloc)
		return null ;
	line = makeline(bloc);
	bloc = newbloc(bloc);
	return line ;
}

char	*pullbloc(int fd, char *bloc)
{
	char	buff[BU + 1];
	int	bytes = 1;
	while (bytes && !hasnl(bloc))
	{
		bytes = read(fd, buff, BU);
		if (bytes == -1)
			return null ;
		buff[bytes] = 0;
		bloc = makebloc(bloc, buff);
	}
	return bloc ;
}


char	*makebloc(char *bloc, char *buff) 
{
	if (!bloc) {
		bloc = (char *) malloc(sizeof(char));
		if (!bloc)
			return null ;
		bloc[0] = 0;
	}
	char	*rest;
	int	size;
	size = len(bloc) + len(buff);
	rest = (char*) malloc(sizeof(char) * (size + 1));
	if (!rest)
		return null ;
	int	i = -1;
	while (bloc[++i])
		rest[i] = bloc[i];
	int	j = 0;
	while (buff[j])	
		rest[i++] = buff[j++];
	rest[i] = 0;
	free(bloc);
	return rest ;
}

char	*makeline(char *bloc){
	if (!len(bloc))	return null ;
	int	i = 0;
	while (bloc[i] && bloc[i] != 10)	i ++;
	char	*line = (char*) malloc(sizeof(char) * (i + 2));
	if (!line)
		return null ;
	i = -1;
	while (bloc[++i] && bloc[i] != 10)
		line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)
		line[i] = bloc[i];
	line[++ i] = 0;
	return line ;
}

char	*newbloc(char *bloc){
	int	i = 0;
	while (bloc[i] && bloc[i] != 10)	i ++;
	if (!bloc[i])
	{
		free(bloc);
		return null ;
	}
	int	size = len(bloc) - i;
	char	*rest = (char *) malloc(sizeof(char) * (size + 1));
	if (!rest)
		return null ;
	int	j = 0;
	i ++;
	while (bloc[i])	rest[j ++] = bloc[i ++];
	rest[j] = 0;
	free(bloc);
	return rest ;
}

char	*hasnl(char *s){
	if (!s)	return 0 ;
	int	i = -1;
	while (s[++ i])
		if (10 == s[i])
			return ((char *) &s[i]);
	return 0 ;
}

int	len(char *s){
	if (!s)	return 0 ;
	int	i = 0;
	while (s[i])	i ++;
	return i ;
}

///	DRIVE

#include "iostream"
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
		L = getnextline(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;

	i = 0;
	f = open("texts/ANM", O_RDONLY);
	while (++i <= 10)
	{
		L = getnextline(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;

	i = 0;
	f = open("texts/RT", O_RDONLY);
	while (++i <= 12)
	{
		L = getnextline(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;
}
