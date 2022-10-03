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

#include "stdio.h"
#include "fcntl.h"  // O_RDONLY
#include "unistd.h" // read and close
#include "stdlib.h" // free, malloc, atoi

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

char    *get_next_line(int);
char    *get_bloc(int, char *);
char    *get_line(char *);
char    *new_bloc(char *);
char    *SJ(char *, char *);
char    *SC(char *, int);
size_t  len(char *);

int	main(int argc, char *argv[])
{
	char    *line;
	int	i = 0, fd, L, T;

        T = (argc == 1) ? 0 : atoi(argv[1]);
        L = (argc == 3) ? atoi(argv[2]) : 16;
        if (!T) L = 8;
        if (argc == 2) {
            if (T == 3 || T == 6)   L = 42;
            if (T == 0) L = 8;
            if (T == 2) L = 9;
            if (T == 4) L = 128;
            if (T == 5) L = 512;
        }

        if (T > 6)  return (1);
        if (T == 1) fd = open("texts/MSP", O_RDONLY);
	if (T == 2) fd = open("texts/RT", O_RDONLY);
        if (T == 3) fd = open("texts/JG", O_RDONLY);
	if (T == 4) fd = open("texts/AOC", O_RDONLY);
	if (T == 5) fd = open("texts/AOC5", O_RDONLY);
	if (T == 6) fd = open("texts/HEAD", O_RDONLY);
	if (T == 0) fd = open("texts/ANM", O_RDONLY);

        printf("--\n");
	while ( ++i < L + 1 ) {
	        line = get_next_line(fd);
		printf("# %02d: %s", i, line);
		if (!line)  printf("\n");
                else        free(line);
	}
        printf("--\nFile option: %i\nRows viewed: %i\n", T, L);
        if (T == 3) printf("(john giorno's poem, 36+ lines)\n");
        if (T == 4) printf("(long text, ~ 100 lines)\n");
        if (T == 5) printf("(AOC 2021 Day 5 input, ~ 500 rows)\n");
        if (T == 6) printf("(headers, 32+ lines)\n");
        printf("--\n");

        close(fd);
        return (0);
}

char    *get_next_line(int fd)
{
        static char     *bloc;
        char            *line;

        if (fd < 0 || BUFFER_SIZE < 1)  return (0);
        bloc = get_bloc(fd, bloc);  // Fn 1: get_bloc
        if (!bloc)  return (NULL);
        line = get_line(bloc);      // Fn 2: get_line: get that line we want!!
        bloc = new_bloc(bloc);      // Fn 3: new_bloc: 

        return (line);
}

char    *get_bloc(int fd, char *bloc)
{
        char    *buff;
        int     n;

        buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));   // allocate space
        if (!buff)  return (NULL);

        n = 1;
        while (!SC(bloc, '\n') && n) // read into buffer BZ bytes a time until nl
        {
            n = read(fd, buff, BUFFER_SIZE);
            if (n == -1)    // handle error
            {
                free(buff);
                return (NULL);
            }
            buff[n] = 0;    // seal the buffer after each buffing
            //printf( "\nbloc before:\n--\n%s\n--\n", bloc );

            bloc = SJ(bloc, buff);  // why no need to bzero the buffer (?)
            //printf( "\nbloc after :\n--\n%s\n--\n", bloc);
            //printf( "\nbuff:\n--\n%s\n--\n", buff );
        }
        //free(buff); // obsolete line

        return (bloc);
}

char    *get_line(char *bloc)
{
        char    *line;
        int     i;

        i = 0;
        if (!bloc[i])   return (NULL);
        while (bloc[i] && bloc[i] != '\n')  i++;
        line = (char *) malloc(sizeof(char) * (i + 2));
        if (!line)      return (NULL);
        i = -1;
        while (bloc[++i] && bloc[i] != '\n')    line[i] = bloc[i];
        if (bloc[i] && bloc[i] == '\n')         line[i] = bloc[i];
        line[++i] = 0;

        return (line);
}

char    *new_bloc(char *bloc)
{
        char    *line;
        int     i;
        int     j;

        i = 0;
        while (bloc[i] && bloc[i] != '\n')  i++;
        if (!bloc[i])
        {
            free(bloc);
            return (NULL);
        }
        line = (char *) malloc(sizeof(char) * (len(bloc) - i + 1));
        if (!line)  return (NULL);
        ++i;
        j = 0;
        while (bloc[i]) line[j++] = bloc[i++];
        line[j] = 0;
        //free(bloc); // obsolete line

        return (line);
}

char	*SJ(char *bloc, char *buff)
{
	char	*res;
	int	size;
	int	i;
	int	j;

	if (!bloc)
	{
		bloc = (char *) malloc(sizeof(char));
		bloc[0] = 0;
	}
	if (!buff)	return (NULL);
	size = len(bloc) + len(buff) + 1;
	res = (char *) malloc(sizeof(char) * size);
	if (!res)	return (NULL);
	i = -1;
	j = 0;
	while (bloc[++i])	res[i] = bloc[i];
	while (buff[j])		res[i++] = buff[j++];
	res[ size - 1 ] = 0;
	free(bloc);

	return (res);
}

char	*SC(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)	return ((char *) &s[i]);
	}
	if (!c)	return ((char *) &s[i]);
	return (0);
}

size_t	len(char *s)
{
	int	i;

	i = 0;
	if (!s)	return (0);
	while (s[i])	i++;
	return (i);
}
