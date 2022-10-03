/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

#include "unistd.h"
#include "stdlib.h"

#ifndef	BU
#define BU 64
#endif

char	*get_next_line(int);
char	*get_bloc(int, char *);
char	*gen_bloc(char *, char *);
char	*get_line(char *);
char	*new_bloc(char *);
char	*sc(int, char *);
int	len(char *);

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
	while (++i < 21)
	{
		L = get_next_line(f);
		printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;
}

//	real stuff

char	*get_next_line(int fd)
{
	static char	*bloc;
	char		*line;

	if (fd < 0 || BU < 1)			return NULL ;
	if (!(bloc = get_bloc(fd, bloc)))	return NULL ;
	line = get_line(bloc);
	bloc = new_bloc(bloc);
	return line ;
}

char	*gen_bloc(char *L, char *R)
{
	char	*temp;
	int	size,i,j;

	if (!len(L))
	{
		if (!(L = (char *) malloc(sizeof(char))))	return NULL ;
		L[0] = 0;
	}
	if (!R)	return NULL ;
	size = len(L) + len(R) + 1;
	if (!(temp = (char *) malloc(sizeof(char) * size)))	return NULL ;
	i = -1;
	while (L[++i])	temp[i] = L[i];
	j = 0;
	while (R[j])	temp[i++] = R[j++];
	temp[size - 1] = 0;
	free(L);
	return temp ;
}

char	*get_bloc(int fd, char *bloc)
{
	char	*buff;
	int	b;

	if (!(buff = (char *) malloc(sizeof(char) * (BU + 1))))	return NULL ;
	b = 1;
	while (b && !sc(10, bloc))		/// XXX type corrected from `!sc(10,buff)`
	{
		b = read(fd, buff, BU);
		if (b == -1)
		{
			free(buff);
			return NULL ;
		}
		buff[b] = 0;			/// XXX missing line
		bloc = gen_bloc(bloc, buff);
	}
	free(buff);
	return bloc ;
}

char	*get_line(char *bloc)
{
	char	*line;
	int	i;

	if (!len(bloc))	return NULL ;
	i = 0;
	while (bloc[i] && bloc[i] != 10)	i ++;
	//if (!(line = (char *)malloc(sizeof(char) * (i + 1))))	return NULL ; /// XXX
	if (!(line = (char*)malloc(sizeof(char) * (i + 2))))	return NULL ;
	i = -1;
	while (bloc[++i] && bloc[i] != 10)	line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)		line[i] = bloc[i];
	line[++i] = 0;
	return line ;
}

char	*new_bloc(char *bloc)
{
	char	*temp;
	int	size,i,j;

	//if (!len(bloc))	return NULL ;
	i = 0;
	while (bloc[i] && bloc[i] != 10)	i ++;
	if (!bloc[i])
	{
		free(bloc);
		return NULL ;
	}
	size = len(bloc) - i;
	if (!(temp = (char*)malloc(sizeof(char) * (size + 1))))	return NULL ;
	//if (bloc[i] && bloc[i] == 10)		i ++;
	i++;
	j = 0;
	while (bloc[i])	temp[j++] = bloc[i++];
	temp[j] = 0;
	free(bloc);
	return temp ;
}

char	*sc(int c, char *s)
{
	int	i = 0;

	if (!s)	return NULL ;
	if (!c)	return ((char *) &s[len(s)]);
	while (s[i])
	{
		if (s[i] == c)	return ((char *) &s[i]);
		i ++;
	}
	return NULL ;
	//return ((char *) &s[i]);	/// XXX: WRONG
}

int	len(char *s)
{
	int	i;

	if (!s)	return 0 ;
	i = 0;
	while (s[i])	i++ ;
	return i ;
}
