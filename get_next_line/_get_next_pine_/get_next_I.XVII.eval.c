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
#ifndef BU
#define BU 32
#endif
#define null NULL
/*char  *get_next_line(int fd);*/
char    *fetch_bloc(int fd, char *);
char    *paste_bloc(char *, char *);
char    *fetch_line(char *);
char    *regen_bloc(char *);
char    *Sch(char *);
int Len(char *);

char    *get_next_line(int fd)
{
    if (fd < 0) return null ;
    if (BU < 1) return null ;
    static char *bloc;
    char        *line;
    bloc = fetch_bloc(fd, bloc);
    if (!bloc)
        return null ;
    line = fetch_line(bloc);
    bloc = regen_bloc(bloc);
    return line ;
}

char    *fetch_bloc(int fd, char *bloc)
{
    //  if (!bloc)  return null ; // FIXME fatal line
    
    int bytes = 1;
    
    //char *buff = (char *) malloc(sizeof(char) * (BU + 1));
    // FIXME no malloc required

    char buff[BU + 1]; 
    // FIXME char[], not char *[]

    //while (bytes && !Sch(buff)) // FIXME check `sch(bloc)` not `buff`
    while (bytes && !Sch(bloc))
    {
        bytes = read(fd, buff, BU);
        if (bytes == -1)
        {
            //free(buff); // FIXME
            return null ;
        }
        buff[bytes] = 0; // FIXME
        bloc = paste_bloc(bloc, buff);
    }
    return bloc ;
}

char*   paste_bloc(char *bloc, char *buff)
{
    if (!bloc)
    {
        bloc = (char *) malloc(sizeof(char));
        bloc[0] = 0;
    }
    int len = Len(bloc) + Len(buff);
    char *res = (char *) malloc(sizeof(char) * (len + 1));
    int i, j;
    i = -1;
    while (bloc[++i])   res[i] = bloc[i];
    j = 0;
    while (buff[j]) res[i ++] = buff[j ++];
    //res[++i] = 0; // FIXME no need to do ++i
    res[i] = 0;

    free(bloc); // FIXME missed
    return res ;
}

/*

fetch
    - Dont check !bloc otherwise all lines turn out null
    - init buff[BU + 1], dont use malloc, thus no free if bytes == -1
    - while (bytes && !sch(bloc)), check sch(bloc), not sch(buff)
    - seal buff at the end of every loop:
        - buff[bytes] = 0
    bloc = paste_bloc(bloc, buff)

paste
    - check !bloc
        - if yes, malloc bloc to size of 1
    - len = Len(bloc) + Len(buff)
    - malloc len + 1 // FIXME
    - copy bloc
    - copy buff
    - seal: res[ i ] = 0
    - free(bloc), Important! bloc replaced by res for the 1st time /// FIXME

get_line
    - check !len(bloc)
        - if yes, return null ;
    - count i until \0 or \n
    - malloc i + 2 // FIXME
    - copy Bloc to Line until potential \n or \0
    - if end is a \n ie. 10, line[i] = bloc[i]
    - seal: line[++i] = 0

regen
    - count i until \0 or \n
    - if end is a \0
        - free(bloc), return null ;
    - size = len(bloc) - i, prepare size covering position \n + 1 to \0
    - malloc size + 1
        - ie. len(bloc) - i + 1
    - i++;
    - j=0;
    - copy bloc[i] to res[j]
    - seal: res[j] = 0
    - free(bloc), Important! replace bloc with res for the 2nd time around /// FIXME 

*/

char*   fetch_line(char *bloc)
{
    if (!Len(bloc)) return null ;
    //if (!bloc[0]) return null ; // FIXME can also do
    int i = 0;
    while (bloc[i] && bloc[i] != 10)    i++;
    char *line = (char *) malloc(sizeof(char) * (i + 2));
    i = -1;
    while (bloc[++i] && bloc[i] != 10)  line[i] = bloc[i];
    if (bloc[i] && bloc[i] == 10)   line[i] = bloc[i];
    line[++i] = 0;
    return line ;
}

char*   regen_bloc(char *bloc)
{
    int i = 0;
    while (bloc[i] && bloc[i] != 10)    i++;
    if (!bloc[i])
    {
        free(bloc);
        return null ;
    }
    int size = Len(bloc) - i ;
    char    *res = (char *) malloc(sizeof(char) * (size + 1));
    i++;
    int j = 0;
    while (bloc[i]) res[j++] = bloc[i++];
    res[j] = 0;
    free(bloc);
    return res ;
}

char *Sch(char *s)
{
    if (!s) return 0 ;
    int i = -1;
    while (s[++i])  if (s[i] == 10) return ((char *) &s[i]) ;
    return 0 ;
}

int Len(char *s)
{
    if (!s) return 0 ;
    int i = 0;
    while (s[i]) i++;
    return i ;
}


//  DRIVE
#include "fcntl.h"
#include "stdio.h"
#define	ss printf("---\n")
#define end printf("\n")

//int	main(int argc, char *argv[])
int main()
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
