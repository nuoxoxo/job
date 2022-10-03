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
#include "readline/readline.h"
#include "readline/history.h"

#define _yellow	"\e[0;33m"
#define _reset	"\e[0;0m"
#define _cyan	"\e[0;36m"
#define _green	"\e[0;32m"

int	len(char *s);

int	main(int c, char **v, char **env)
{
	if (c ^ 1)
		return (1);
	printf( _green "welcome! \n" _reset);

	char		*prompt = _cyan "seashell: " _reset;
	char		*candle;

	while ((int) 1e6)
	{
		candle = readline(prompt);
		if (len(candle))
			printf( _yellow "\t  %s \n" _reset , candle);
	}
	(void) v;
	(void) env;
	return (0);
}

int	len(char *s)
{
	int		i;

	i = 0;
	while (s[i] && ++i);
	return (i);
}
