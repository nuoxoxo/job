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

#include "get_next_line.h"
//#include "get_next_jan04.h"
#include "unistd.h"
//#include "fcntl.h"
//#include <stdlib.h>

//#ifndef	BUFFER_SIZE
//#define	BUFFER_SIZE 32
//#endif

#include "stdio.h"
#define ss printf("---\n")

char	*get_next_line(int);
char	*get_chunk(int, char *);
char	*get_words(char *);
char	*new_chunk(char *);
char	*C(int, char *);
char	*J(char *, char *);

char	*get_next_line(int f)
{
	static char	*chunk;
	char		*words;

	if (f < 0 || BUFFER_SIZE < 1)
		return (0) ;
	chunk = get_chunk(f, chunk);
	if (!chunk)
		return (NULL) ;
	words = get_words(chunk);
	chunk = new_chunk(chunk);
	return (words) ;
}

/*
char	*get_chunk(int f, char *chunk)
{
	char	*buff;
	int	bytes;

	buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bytes = 1;
	while (!C(10, chunk) && bytes)
	{
		bytes = read(f, buff, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL) ;
		buff[ bytes ] = '\0' ;
		chunk = J(chunk, buff);
	}
	return (chunk) ;
}

char	*get_words(char *chunk)
{
	char	*words;
	int	i;

	i = 0;
	if (!chunk[i])
		return (NULL) ;
	while (chunk[i] && chunk[i] != 10)
		i ++ ;
	words = (char *) malloc(sizeof(char) * (i + 2));
	i = -1;
	while (chunk[++i] && chunk[i] != 10)
		words[i] = chunk[i];
	if (chunk[i] && chunk[i] == 10)
		words[i] = chunk[i];
	words[++i] = '\0';
	return (words) ;
}

char	*new_chunk(char *chunk)
{
	char	*words;
	int	len;
	int	i;
	int	j;

	i = 0;
	while (chunk[i] && chunk[i] != 10)
		i ++ ;
	if (!chunk[i])
		return (NULL) ;
	len = 0;
	//	if ... -> while ...
	while (chunk[ len ])
		len ++ ;
	words = (char *) malloc(sizeof(char) * (len - i + 1));
	if (!words)
		return (NULL) ;
	i ++ ;
	j = 0;
	while (chunk[i])
		words[j++] = chunk[i++];
	words[j] = '\0';
	return (words) ;
}

char	*J(char *chunk, char *buff)
{
	char	*rest;
	int	size_chunk;
	int	size_total;
	int	i;
	int	j;

	size_total = 0;
	if (!buff)
		return (NULL) ;
	else
	{
		while (buff[ size_total ])
			size_total ++ ;
	}
	size_chunk = 0;
	if (!chunk)
	{
		chunk = (char *) malloc(sizeof(char));
		if (!chunk)
			return (NULL) ;
		chunk[0] = 0;
	}
	else
	{
		while (chunk[ size_chunk ])
			size_chunk ++ ;
	}
	size_total += size_chunk + 1;
	rest = (char *) malloc(sizeof(char) * size_total);
	if (!rest)
		return (NULL) ;
	i = -1;
	while (chunk[++i])
		rest[i] = chunk[i];
	j = 0;
	while (buff[j])
		rest[i++] = buff[j++];
	rest[ size_total - 1 ] = 0;
	return (rest) ;
}

char	*C(int c, char *s)
{
	int	i;

	if (!s)
		return (0) ;
	i = -1;
	while (s[++i])
	{
		if (c == s[i])
			return ((char *) &s[i]) ;
	}
	if (!c)
		return ((char *) &s[i]) ;
	return (0) ;
}
*/

//	SPLITTINget_next_line

/*
int	main(int argc, char *argv[])
{
        char	*words;
	int f, i = 0;
        int T = (argc == 1) ? 0 : atoi(argv[1]);
        int L = (argc == 3) ? atoi(argv[2]) : 16;

        T = T < 7 ? T : 1;
        if (!T) L = 8;
        if (argc == 2) {
            if (T == 3) L = 42;
            if (T == 6) L = 42;
            if (T == 0) L = 8;
            if (T == 2) L = 10;
            if (T == 4) L = 128;
            if (T == 5) L = 512;
        }
        if (T == 1) f = open("texts/MSP", O_RDONLY);
	if (T == 2) f = open("texts/RT", O_RDONLY);
        if (T == 3) f = open("texts/JG", O_RDONLY);
	if (T == 4) f = open("texts/AOC", O_RDONLY);
	if (T == 5) f = open("texts/AOC5", O_RDONLY);
	if (T == 6) f = open("texts/HEAD", O_RDONLY);
	if (T == 0) f = open("texts/ANM", O_RDONLY);
	if (T == 0) f = open("texts/ANM", O_RDONLY);
        ss;
        while( ++i < L + 1 ) {
            words = get_next_line(f);
            printf("# %02d: %s", i, words);  /// display #1

            //cout << "# ";                 /// display #2 - segfault if !words
            //if (i < 10) cout << '0';
            //cout << i << ": " << words;

            if (!words)
                printf("\n");
            else
                free(words);
        }
        ss;
        close(f);
        return 0;
}
*/
