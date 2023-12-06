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

int	_strcmp(const char *, const char *);
int	_len(const char *s);

int	main(int c, char **v, char **env)
{
	int		i;

	if (c == 1)
	{
		printf("%s \n", *env);
		return (0);
	}
	if (c ^ 2)
		return (0);
	if (_strcmp(v[1], "more") && _strcmp(v[1], "all") && _strcmp(v[1], "less"))
		return (0);
	i = -1;
	while (env[++i])
	{
		if (! _strcmp(v[1], "less") && _len(env[i]) > 42)
			continue ;
		printf("%s \n", env[i]);
	}
	(void) v;
	return (0);
}

int	_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	        i++;
	return (s1[i] - s2[i]);
}

int	_len(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && ++i);
	return (i);
}
