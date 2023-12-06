/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_params_digit_and_limit(const int c, const char **v);
int		check_params_digit(const char *s);
int		check_params_limit(const char *s);

void	check_params(const int c, const char **v)
{
	int		v1;
	int		v2;
	int		v3;
	int		v4;
	int		v5;

	if (c < 5 || c > 6)
		usage_exit();
	check_params_digit_and_limit(c, v);
	v1 = ft_atoi(v[1]);
	v2 = ft_atoi(v[2]);
	v3 = ft_atoi(v[3]);
	v4 = ft_atoi(v[4]);
	if (c == 6)
	{
		v5 = ft_atoi(v[5]);
	}
	else
	{
		v5 = 1e9;
	}
	if (v1 < 1 || v2 < 1 || v3 < 1 || v4 < 1 || v5 < 1)
		usage_exit();
}

void	check_params_digit_and_limit(const int c, const char **v)
{
	int		i;

	i = 0;
	while (++i < c)
	{
		if (check_params_digit(v[i]) || check_params_limit(v[i]))
			usage_exit();
	}
}

int	check_params_digit(const char *s)
{
	int	i;

	i = -1;
	if (s[i + 1] == '-' || s[i + 1] == '+')
		i++;
	while (s[++i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
	}
	return (0);
}

int	check_params_limit(const char *s)
{
	long long	l;

	l = ft_atoll(s);
	if (l < -2147483648 || l > 2147483647)
		return (1);
	return (0);
}
