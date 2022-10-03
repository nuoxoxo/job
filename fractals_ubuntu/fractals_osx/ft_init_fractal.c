/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_init_fractal.c                                  :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_loop_fractol(t_vars *v);

void	ft_init_fractal(t_vars *v)
{
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
			ft_setup_julia_c(v);
			ft_loop_fractol(v);
			ft_pixel(v->it1, v->it2, v, v->iteration_current);
			++v->it2;
		}
		++v->it1;
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	ft_panel_show(v);
}

void	ft_loop_fractol(t_vars *v)
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
	if (v->iteration_current == v->iteration_limit / 2)
	{
		v->iteration_current = 0;
	}
}

int	ft_panel_show(t_vars *v)
{
	int	x;

	x = 32;
	if (!(v->panel))
		return (1);
	mlx_string_put(v->mlx, v->win, x, x + 0, 0x2DFFFF, "CONTROL:");
	mlx_string_put(v->mlx, v->win, x, x + 40, 0xFFFFFF, "Move = w a s d");
	mlx_string_put(v->mlx, v->win, x, x + 60, 0xFFFFFF, "Move = ^ < v >");
	mlx_string_put(v->mlx, v->win, x, x + 80, 0xFFFFFF, "Zoom = Wheel");
	mlx_string_put(v->mlx, v->win,
		x, x + 100, 0xFFFFFF, "Switch = Mouse R");
	mlx_string_put(v->mlx, v->win, x, x + 120, -1, "Freeze = Mouse L");
	mlx_string_put(v->mlx, v->win, x, x + 140, 0xFFFFFF, "Reset = R");
	mlx_string_put(v->mlx, v->win, x, x + 160, 0xFFFFFF, "Panel = P");
	mlx_string_put(v->mlx, v->win, x, x + 180, 0xFFFFFF, "Quit = ESC");
	return (0);
}
