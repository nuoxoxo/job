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
/* ****************************************************************** nxu *** */

#include "stdio.h"
#include "stdlib.h"	/* atoi */
#include "unistd.h"	/* getcwd . chdir */

#define _yel "\e[0;33m"
#define _res "\e[0;0m"
#define _cyn "\e[0;36m"
#define _grn "\e[0;32m"
#define LEN 100

int	main(int argc, char **argv)
{
	//char	*s; /* bus error */
	char	s[100];
	int	i, n;

	if (argc == 2)
	{
		n = atoi(argv[1]) ? atoi(argv[1]) : 1;
	}
	else
	{
		n = 1;
	}
	printf("\ndo \"chdir ..\" \n\t%d \ntime(s): \n\n", n);
	printf( _cyn "where are we now: \n" _res);
	printf( _yel "%s \n\n" _res, getcwd(s, LEN));
	i = -1;
	while (++i < n)
	{
		chdir("..");
		printf( _grn "getcwd (%d): \n" _res , i + 1);
		printf("%s \n\n", getcwd(s, LEN));
	}
}
