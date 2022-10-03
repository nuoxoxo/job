/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_init_julia.c                                    :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/18 13:13:38 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_stof_helper(const char *s);
double	ft_stof(const char *s);

void	ft_init_julia(const char *s1, const char *s2, t_vars *v)
{
	double		x;
	double		y;

	if (!ft_stof_checker(s1) || !ft_stof_checker(s2))
		ft_prompt();
	ft_printf("%s, %s \n", s1, s2);
	ft_init_vars(v);
	v->set = 1;
	x = ft_stof(s1);
	y = ft_stof(s2);
	if (x > v->width || y > v->height)
		ft_prompt();
	v->julia_plot = TRUE;
	v->cx = x;
	v->cy = -y;
}

double	ft_stof(const char *s)
{
	int		factor;

	factor = 1;
	if (*s == '-')
	{
		++s;
		factor = -1;
	}
	else if (*s == '+')
		++s;
	return (factor * ft_stof_helper(s));
}

double	ft_stof_helper(const char *s)
{
	double		val;
	int			i;
	int			flag;

	i = 0;
	val = 0;
	flag = 0;
	while (*s && val < 1e6)
	{
		if (*s != '.')
		{
			val = (val * 10) + (*s - '0');
			if (flag == 1)
				--i;
		}
		else
		{
			if (flag == 1)
				return (0);
			flag = 1;
		}
		++s;
	}
	return (val * pow(10, i));
}

int	ft_stof_checker(const char *s)
{
	int		i;

	i = 0;
	if (s[i] == '-' || s[i] == '+')
		++i;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	++i;
	if (s[i] == '.')
		++i;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		++s;
	}
	return (1);
}

/*
double	ft_stof(const char* s)
{
	double	factor;
	double	res;
	int		dcp;
	double		d;

	res = 0;
	factor = 1;
	if (*s == '-')
	{
		++s;
		factor = -1;
	}
	dcp = 0;
	while (*s)
	{
		if (*s == '.')
		{
			dcp = 1;
			continue ;
		}
		d = *s - '0';
		printf("Hi from stof : d = %d \n", d);
		if (d < 10 && d > -1)
		{
			if (dcp)
				factor /= 10.0f;
			res = res * 10.0f + (double) d;
		}
		printf("Hi from stof : d = %f \n", res);
		++s;
	}
	return (res * factor);
}
*/
