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
char	*Gen(char *, char *);
char	*get_line(char *);
char	*new_bloc(char *);
char	*SC(int, char *);
int	len(char *);

//	CURRENT EDIT :: line-wrapped, no malloc check
//	malloc must be done this way though: (char *) malloc

int	len(char *s)
{
	if (!s) return 0 ;
	int i = 0;
	while (s[i]) i++;
	return i ;
}

char	*SC(int c, char *s)
{
	int	i;
	if (!s)	return NULL ;
	if (!c)	return ((char *) &s[len(s)]) ;

	//i = -1;
	//while (s[++i])	if (c == s[i])	return ((char *) &s[i]); // XXX Crucial line

	i = 0;
	while (s[i])
	{
		if (c == s[i])	return ((char *) &s[i]);
		i ++;
	}
	
	return NULL ;
}

char	*new_bloc(char *bloc)
{
	char	*temp;
	int	size, i, j; // XXX missed j

	//if (!bloc)	return NULL ;

	i = 0;
	while (bloc[i] && bloc[i] != 10)	i++;

	if (!bloc[i])
	//if (!bloc[0])
	
	{
		free(bloc);
		return NULL ;
	}
	size = len(bloc) - i;
	temp = (char *) malloc(sizeof(char) * (size + 1));

	//i = -1; // XXX
	i++ ;

	j = 0; // XXX missing

	while (bloc[i])	temp[j++] = bloc[i++];
	temp[j] = 0; /// XXX Crucial line 

	free(bloc);
	return temp ;
}

char	*get_line(char *bloc)
{
	char	*line;
	int	i;
	if (!len(bloc))	return NULL ;
	//if (!len(bloc))	return NULL ;
	//if (!bloc[0])	return NULL ; // XXX
	i = 0;
	while (bloc[i] && bloc[i] != 10)	i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	i = -1;
	while (bloc[++i] && bloc[i] != 10)	line[i] = bloc[i];
	if (bloc[i] && bloc[i] == 10)		line[i] = bloc[i];
	line[++i] = 0;
	return line ;
}

char	*get_bloc(int fd, char *bloc)
{
	char	*buff;
	int	bytes;
	buff = (char *) malloc(sizeof(char) * (BU + 1));
	bytes = 1;
	
	//while (bytes && !SC(10, buff))
	while (bytes && !SC(10, bloc)) /// XXX Crucial line
	{
		bytes = read(fd, buff, BU);
		if (bytes == -1)
		{
			free(buff);
			return NULL ;
		}
		buff[bytes] = 0;	// XXX
		//buff[BU] = 0;

		bloc = Gen(bloc, buff);
	}
	free(buff);
	return bloc ;
}

char	*Gen(char *bloc, char *buff)
{
	char	*temp;
	int	size, i, j;

	if (!buff)	return NULL ; // **** note : we check bloc's memory and len(bloc)
	if (!len(bloc))	bloc = (char *) malloc(sizeof(char)), bloc[0] = 0;
	//if(!bloc[0])	bloc = (char *) malloc(sizeof(char)), bloc[0] = 0;// XXX

//	if (!buff)	return NULL ; // why ??? TODO

	size = len(bloc) + len(buff);
	temp = (char *) malloc(sizeof(char) * (size + 1));
	i = -1;
	while (bloc[++i])	temp[i] = bloc[i];
	j = 0;
	while (buff[j])		temp[i++] = buff[j++];
	temp[size] = 0;
	free(bloc);
	//free(buff);	double free otherwise
	return temp ;
}

char	*get_next_line(int fd)
{
	static char	*bloc;
	char		*line;
	if (fd < 0)	return NULL ;
	if (BU < 1)	return NULL ;
	bloc = get_bloc(fd, bloc);
	if (!bloc)	return NULL ;
	line = get_line(bloc);
	bloc = new_bloc(bloc);
	return line ;
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
