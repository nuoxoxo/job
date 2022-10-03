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

///     authorized

//#include "get_next_line.h"
#include "unistd.h"

///     allowed (defined in .h)

#include "stdlib.h"

#ifndef S
#define S 32
#endif

///     prohibited

#include "stdio.h"
#include "fcntl.h"

///     dependencies (defined in .h)

char    *get_next_line(int);
char    *get_bloc(int, char *);
char    *get_line(char *);
char    *new_bloc(char *);
char    *SJ(char *, char *);
char    *SC(char *, int);
int     len(char *);

//      DRIVE

#define SP printf("--\n")
#define NL printf("\n")

int     main()
{
        int M = 23;

        char *line;
        int f = open("texts/ANM", O_RDONLY);
        //int f = open("texts/RT", O_RDONLY);
        //int f = open("texts/MSP", O_RDONLY);
        int i = 0;

        SP;
        while ( ++i < M )
        {
            line = get_next_line(f);
            printf("# %02d: %s", i ,line);
            if (!line)  NL;
            else free(line);
        }
        SP; close(f);
}

//  BODY

char    *get_next_line(int f)
{
        static char *bloc;

        if ( f < 0 || S < 1 )               return 0;
        if ( !(bloc = get_bloc(f, bloc)) )  return NULL;
        char *line;
        line = get_line(bloc);
        bloc = new_bloc(bloc);

        return (line);
}

char    *get_bloc(int f, char *bloc)
{
        char    *buff;

        if (!(buff = (char *) malloc(sizeof(char) * (S + 1))))  return NULL;

        int B = 1; // bytes read
        while (B && !SC(bloc, 10))
        {
            B = read(f, buff, S);
            if (B == -1)
            {
                free(buff);
                return NULL;
            }
            buff[B] = 0;    // seal it
            bloc = SJ(bloc, buff);
        }
        free(buff);

        return (bloc);
}

char    *get_line(char *bloc)
{
        if ( !bloc[0] ) return NULL; // <-- if "if (!bloc)" then won't print "(null)"
        int L = 0;
        while ( bloc[L] && bloc[L] != 10 )  L ++;
        char *line;
        line = (char *) malloc(sizeof(char) * (L + 2));
        if (!line)  return NULL;
        int i = -1;
        while (bloc[++ i] && bloc[i] != 10) line[i] = bloc[i];
        if (bloc[i] && bloc[i] == 10)       line[i] = bloc[i];
        line[++ i] = 0;

        return (line);
}

char    *new_bloc(char *bloc)
{
        int i = 0;
        while ( bloc[i] && bloc[i] != 10 )  i ++;
        if (!bloc[i])
        {
            free(bloc);
            return NULL;
        }
        char *line;
        if (!(line = (char *) malloc(sizeof(char) * (len(bloc) - i + 1))))  return NULL;
        int j = 0;
        i ++;
        while (bloc[i]) line[j++] = bloc[i++];
        line[j] = 0;
        free(bloc);

        return (line);
}

char    *SJ(char *bloc, char *buff)
{
        if (!bloc)  bloc = (char *) malloc(sizeof(char)), bloc[0] = 0;
        if (!buff)  return NULL;
        char    *res;
        int     size = len(bloc) + len(buff) + 1;
        if (!(res = (char *) malloc(sizeof(char) * size)))  return NULL;
        int i = -1;
        while ( bloc[++i] ) res[i] = bloc[i];
        int j = 0;
        while (buff[j]) res[i++] = buff[j++];
        res[size - 1] = 0;

        return (res);
}

char    *SC(char *s, int c)
{
        if (!s) return 0;
        int i = -1;
        while (s[++i])  if (s[i] == c)  return ((char *) &s[i]);
        if (!c) return ((char *) &s[i]);

        return 0;
}

int     len(char *s)
{
        if (!s) return 0;
        int i = 0;
        while ( s[i] )  i ++;

        return (i);
}
