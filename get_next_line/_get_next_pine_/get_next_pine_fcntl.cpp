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

#include "iostream"
#include "fcntl.h"  // open and O_RDONLY
#include "unistd.h" // read and close

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

char    *GNL(int, char *&);
char    *get_bloc(int, char *&);
char    *get_line(char *&);
char    *new_bloc(char *&);
char    *SJ(char *, char *);
char    *SC(char *, int);
size_t  len(char *);

using   namespace std;

#define SEP printf("--\n")

int	main(int argc, char *argv[])
{
	char    *bloc;
        char    *line;
	int     fd, i = 0;

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
        if (T == 1) fd = open("texts/MSP", O_RDONLY);
	if (T == 2) fd = open("texts/RT", O_RDONLY);
        if (T == 3) fd = open("texts/JG", O_RDONLY);
	if (T == 4) fd = open("texts/AOC", O_RDONLY);
	if (T == 5) fd = open("texts/AOC5", O_RDONLY);
	if (T == 6) fd = open("texts/HEAD", O_RDONLY);
	if (T == 0) fd = open("texts/ANM", O_RDONLY);
	if (T == 0) fd = open("texts/ANM", O_RDONLY);
        SEP;
        while ( ++i < L + 1 ) {
            line = GNL(fd, bloc);
            printf("# %02d: %s", i, line);  /// display #1
            /*cout << "# ";                 /// display #2 - segfault if !line
            if (i < 10) cout << '0';
            cout << i << ": " << line;
            */
            if (!line)
                cout << '\n';
            else
                free(line);
        }
        SEP;
        close(fd);

        return 0;
}

char    *GNL(int fd, char *& bloc)
{
        char    *line;

        if (fd < 0 || BUFFER_SIZE < 1)  return (0);
        bloc = get_bloc(fd, bloc);
        if (!bloc)  return (NULL);
        line = get_line(bloc);
        bloc = new_bloc(bloc);

        return (line);
}

char    *get_bloc(int fd, char *& bloc)
{
        char    *buff;
        int     B;

        buff = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if (!buff)      return (NULL);

        B = 1;
        while (!SC(bloc, '\n') && B)
        {
            B = read(fd, buff, BUFFER_SIZE);
            if (B == -1)
            {
                free(buff);
                return (NULL);
            }
            buff[B] = 0;
            bloc = SJ(bloc, buff);
        }
        free(buff);

        return (bloc);
}

char    *get_line(char *& bloc)
{
        char    *line;
        int     i;

        i = 0;
        if (!bloc[i])   return (NULL);
        while (bloc[i] && bloc[i] != '\n')  i++;
        if (!(line = (char *) malloc(sizeof(char) * (i + 2))))  return (NULL);
        i = -1;
        while (bloc[++i] && bloc[i] != '\n')    line[i] = bloc[i];
        if (bloc[i] && bloc[i] == '\n')         line[i] = bloc[i];
        line[++i] = 0;

        return (line);
}

char    *new_bloc(char *& bloc)
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
        if (!(line = (char *) malloc(sizeof(char) * (len(bloc) - i + 1))))
            return (NULL);
        ++i;
        j = 0;
        while (bloc[i]) line[j++] = bloc[i++];
        line[j] = 0;
        free(bloc);

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
            if (!(bloc = (char *) malloc(sizeof(char))))    return NULL;
            bloc[0] = 0;
	}
	size = len(bloc) + len(buff) + 1;
	if (!(res = (char *) malloc(sizeof(char) * size)))  return NULL;
	i = -1;
	j = 0;
	while (bloc[++i])   res[i] = bloc[i];
	while (buff[j])	    res[i++] = buff[j++];
	res[ size - 1 ] = 0;
        //free(bloc);

	return (res);
}

char	*SC(char *s, int c)
{
	int	i;

	if (!s) return (0);
	i = -1;
	while (s[++i])  if (s[i] == c)  return ((char *) &s[i]);
	if (!c) return ((char *) &s[i]);

        return (0);
}

size_t	len(char *s)
{
	int i = 0;

	if (!s)	return (0);
	while (s[i])	i++;

        return (i);
}
