/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_init_fractal.c                                  :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/18 13:25:16 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_algorithm(t_vars *_);

int	ft_init_fractal(t_vars *v)
{
	if (v->win == NULL)
		return (1);
	v->it1 = 0;
	while (v->it1 < v->width)
	{
		v->it2 = 0;
		while (v->it2 < v->height)
		{
			v->iteration_current = 0;
			v->x = ft_mapx(v->it1, v);
			v->y = ft_mapy(v->it2, v);
			ft_setup_mandelbar_bc(v);
			if (!v->julia_plot)
				ft_setup_julia_c(v);
			ft_algorithm(v);
			ft_setup_color(v->it1, v->it2, v, v->iteration_current);
			v->it2 += 1;
		}
		v->it1 += 1;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	ft_panel_show(v);
	return (0);
}

void	ft_algorithm(t_vars *v)
{
	double	twoab;
	double	aa;
	double	bb;
	double	a;
	double	b;

	a = v->x;
	b = v->y;
	while (v->iteration_current < v->iteration_limit)
	{
		aa = a * a;
		bb = b * b;
		twoab = a * b * v->bc;
		if (v->set == 3 && twoab < 0)
			twoab *= -1;
		a = aa - bb + v->cx;
		b = twoab + v->cy;
		if (aa * aa + bb * bb > v->bound)
			break ;
		v->iteration_current++;
	}
	if (v->iteration_current == v->iteration_limit)
	{
		v->iteration_current = 0;
	}
}
