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

#include "unistd.h"
#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"
//#include "./../minishell.h"

int	_len(char *s);
void    _putstr(char const *s);
int	_echo(char *v, int n_flag);

int	main(int c, char **v, char **env)
{
	char		*prompt = "seashell: ";
	char		*candle;

	if (c ^ 1)
		return (1);
	printf("\nhello echo!\n\n");
	while ((int) 1e6)
	{
		candle = readline(prompt);
		if (_len(candle))	
		{
			_echo(candle, 1);
		}
	}
	(void) v;
	(void) env;
	return (0);
}

/*	try echo	*/

int	_echo(char *v, int has_n_flag)
{
	if (!v)
		return (1);
	_putstr(v);
	if (has_n_flag)
		_putstr("\n" );
	return (0);
}

/*	utils		*/

void    _putstr(char const *s)
{
	if (! s)
		return ;
        while (*s)
		write(1, s++, 1);
}

int	_len(char *s)
{
	int		i;

	i = 0;
	if (s)
		while (s[i] && ++i);
	return (i);
}
