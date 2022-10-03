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

///     allowed

//#include "get_next_line.h"
#include "unistd.h"

///     allowed - defined in get_next_line.h

#include "stdlib.h"

#ifndef S
#define S 64
#endif

///     banned - used only for testing

#include "stdio.h"
#include "fcntl.h"

///     dependencies - defined in get_next_line.h

char    *get_next_line(int fd);

char    *get_bloc(int, char *);
char    *get_line(char *);
char    *new_bloc(char *);

char    *SJ(char *, char *);
char    *SC(char *, int);
int     len(char *);

///     definitions

char    *get_next_line(int f)
{
        char        *line;
        static char *bloc; // will resume at each GNL call even if declared everytime

        if (f < 0)
            return (0);
        if (S < 1)
            return (0);
        if (!(bloc = get_bloc(f, bloc)))
            return (NULL);
        line = get_line(bloc);
        bloc = new_bloc(bloc);

        return (line);
}

char    *get_bloc(int f, char *bloc)
{
        char    *buff;
        int     bytes;

        if (!(buff = (char *) malloc(sizeof(char) * (S + 1))))
            return (NULL);
        bytes = 1;
        while (bytes && !SC(bloc, 10))
        {
            bytes = read(f, buff, S);
            if (bytes == -1)
            {
                free(buff);
                return (NULL);
            }
            buff[bytes] = 0;
            bloc = SJ(bloc, buff);
        }
        free(buff);

        return (bloc);
}

char    *get_line(char *bloc)
{
        char    *line;
        int     L, i;

        if (!bloc[0])
            return (NULL);
        i = 0;
        while (bloc[++i] && bloc[i] != 10)
            continue ;
        L = i + 2;
        if (!(line = (char *) malloc(sizeof(char) * L)))
            return (NULL);
        i = -1;
        while (bloc[++i] && bloc[i] != 10)
            line[i] = bloc[i];
        if (bloc[i] && bloc[i] == 10)
            line[i] = bloc[i];
        line[++i] = 0;

        return (line);
}

char    *new_bloc(char *bloc)
{
        char    *line;
        int     i, j;

        i = 0;
        while (bloc[++i] && bloc[i] != 10)
            continue ;
        if (!bloc[i])
        {
            free(bloc);
            return (NULL);
        }
        if (!(line = (char *) malloc(sizeof(char) * (len(bloc) - i + 1))))
            return (NULL);
        i += 1;
        j = 0;
        while (bloc[i])
            line[j++] = bloc[i++];
        line[j] = 0;
        free(bloc);

        return (line);
}

char    *SJ(char *bloc, char *buff)
{
        char    *res;
        int     size, i, j;

        if (!bloc)
        {
            bloc = (char *) malloc(sizeof(char));
            bloc[0] = 0;
        }
        if (!buff)
            return (NULL);
        size = len(bloc) + len(buff) + 1;
        if (!(res = (char *) malloc(sizeof(char) * size)))
            return (NULL);
        i = -1;
        while (bloc[++i])
            res[i] = bloc[i];
        j = 0;
        while (buff[j])
            res[i++] = buff[j++];
        res[size - 1] = 0;

        return (res);
}

char    *SC(char *s, int c)
{
        int i;

        if (!s)
            return (0);
        i = -1;
        while (s[++i])
        {
            if (s[i] == c)
                return ((char *) &s[i]);
        }
        if (!c)
            return ((char *) &s[i]);

        return (0);
}

int     len(char *s)
{
        int i;

        if (!s)
            return (0);
        i = 0;
        while (s[++i])
            continue ;

        return (i);
}

//      DRIVE

#define SP printf("--\n")
#define NL printf("\n")

int     main()
{
        char *line;
        int M = 23;
        int i = 0;
        int f;
        //f = open("texts/ANM", O_RDONLY);
        //f = open("texts/RT", O_RDONLY);
        f = open("texts/MSP", O_RDONLY);
        SP;
        while ( ++i < M )
        {
            line = get_next_line(f);
            printf("# %02d: %s", i ,line);
            if (!line)  NL;
            else free(line);
        }
        SP;
        close(f);
}
