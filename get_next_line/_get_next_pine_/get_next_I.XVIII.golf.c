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


#include "stdlib.h"
#include "unistd.h"


char *stos(char *s)
{
    // no checks neeeded FIXME

    //if (!s) return NULL ; /// obsolete line FIXME

    int i = 0;
    while (s[i])    i++;
    char *d = malloc(i+1);
    char *p = d;
    //p=d;
    while (*s) *d++ = *s++;
    *d = 0;
    return p ;
}


char *get_next_line(int fd)
{
    char c, line[(int)1e6] = {};
    int B = 1, i = 0;
    while (B)
    {
        B = read(fd, &c, 1);
        if (B < 1)
            break ;
        line[i++] = c;
        if (c == 10)
            break ; 
    }
    if (line[0] == 0)   return NULL ;
    return stos(line) ;
}


/*

#include "fcntl.h"
#include "stdio.h"
#define	ss printf("---\n")
#define end printf("\n")

int	main()
{
	char	*L;
	int	f, i;

	ss;
	f = open("texts/MSP", O_RDONLY);
	i = 0;
	while (++i < 17){
		L = get_next_line(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;
	f = open("texts/ANM", O_RDONLY);
	i = 0;
	while (++i <= 10){
		L = get_next_line(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;
	f = open("texts/RT", O_RDONLY);
	i = 0;
	while (++i <= 12) {
		L = get_next_line(f), printf("# %0.2d: %s", i, L);
		if (!L)	end;
		else	free(L);
	}
	close(f);
	ss;
}

*/



