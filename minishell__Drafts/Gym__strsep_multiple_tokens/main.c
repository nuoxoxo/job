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

#include "string.h"
#include "unistd.h"
#include "stdio.h"

#define _reset	"\e[0;0m"
#define _green	"\e[0;32m"

int	main(int argc, char **argv)
{
	char	*s, *token;
	int		i;

	if (argc ^ 3)
	{
		// using fprintf a.k.a. FILE*stream-print-format */

		// fprintf(
		// 	stderr,
		// 	"Usage: ./%s  [ string ]  [ delimiter_char ] \n",
		// 	argv[0]
		// );
		
		/* or just write */
		write(2, "Usage:  ", 8);
		write(2, argv[0], strlen(argv[0]));
		write(2, " [ sourceString ] [ delimiterChar ]\n", 36);

		return (1);
	}
	s = strdup(argv[1]);
	printf("source  : ");
	printf( _green "\'%s\'\n" _reset , s);
	i = 0;
	while( (token = strsep(& s, argv[2])))
	{
		printf("token[%d]: %s \n", i++, token);
	}
	return(0);
}
