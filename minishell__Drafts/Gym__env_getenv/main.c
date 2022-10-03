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

#include "stdlib.h" /* getenv */
#include "stdio.h"

#define _red	"\e[0;31m"
#define _gre	"\e[0;32m"
#define _yel	"\e[0;33m"
#define _blu	"\e[0;34m"
#define _mag	"\e[0;35m"
#define _cyn	"\e[0;36m"
#define _res	"\e[0;0m"

#define sc1 printf( _gre "\n----8<---- now showing the **env list: ---------- \n" _res );
#define sc2 printf( _gre "\n----8<---- now showing home and user : ---------- \n" _res );
#define sc3 printf( _gre "\n----8<---- now showing what you want : ---------- \n" _res );
#define nl2 printf("\n\n")
#define nl1 printf("\n")

int	main(int argc, char **argv, char **env)
{
	int		i;

	if (argc == 1)
	{
		i = -1;
		sc1;
		nl1;
		while (env[++i])
		{
			printf("%s \n", env[i]);
		}
		nl1;
		sc2;
		nl1;
		printf("TERM_PG\t: %s\n", getenv("TERM_PROGRAM"));
		printf("LOGNAME\t: %s\n", getenv("LOGNAME"));
		printf("USER \t: %s\n", getenv("USER"));
		printf("HOME \t: %s\n", getenv("HOME"));
		printf("SHELL \t: %s\n", getenv("SHELL"));
		printf("ZSH \t: %s\n", getenv("ZSH"));
	}
	else if (argc == 2)
	{
		sc3;
		nl1;
		printf("[ %s ] : %s ", argv[1], getenv(argv[1]));
	}
	return nl2, 0;
}
