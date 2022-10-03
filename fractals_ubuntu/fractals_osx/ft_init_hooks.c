/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

//int	ft_mouse_down(int code, int x, int y, t_vars *v);
//int	ft_mouse_move(int x, int y, t_vars *v);
//int	ft_key_down(int code, t_vars *v);

void	ft_init_hooks(t_vars *v)
{
	mlx_hook(v->win, 6, 0, ft_mouse_move, v);
	mlx_hook(v->win, 4, 0, ft_mouse_down, v);
	mlx_hook(v->win, 2, 0, ft_key_down, v);
	mlx_loop(v->mlx);
}

//	some irregularities

/*
 * 	"mlx_hook( )"
 *
 * mlx_hook(v->win, 6, 0, mouse_move, v);	// osx : yes
 * mlx_hook(v->win, 6, 0, mouse_post, v);	// osx : yes
 *
 * 			/// both "6" hook used at once : XXX
 * 
 * mlx_hook(v->win, 4, 0, mouse_down, v);	// osx : yes
 * mlx_hook(v->win, 2, 0, key_down, v);		// linux : yes
 *
 */

/*
 *	individual hooks
 *
 * mlx_mouse_hook(v->win, mouse_down, v);	// linux : yes
 * mlx_key_hook(v->win, key_down, v);		// linux : yes
 * 
 * mlx_mouse_hook(v->win, mouse_move, v);	// linux + osx : XXX
 * mlx_mouse_hook(v->win, mouse_post, v);	// linux + osx : XXX
 *
 */

int	ft_key_down(int code, t_vars *v)
{
	ft_move_horizontal(code, v);
	ft_move_vertical(code, v);
	ft_panel_toggle(code, v);
	ft_destroy(code, v);
	ft_reset(code, v);
	if (code == 49)
	{
		ft_switch(code, v);
	}
	ft_press_g(code, v);
	ft_press_del(code, v);
	ft_init_fractal(v);
	return (0);
}

int	ft_mouse_down(int code, int x, int y, t_vars *v)
{
	double	rate;
	int		new_x;
	int		new_y;

	rate = 0;
	new_x = x;
	new_y = y;
	ft_reset(code, v);
	ft_freeze(code, v);
	if (code == 4 || code == 5)
	{
		ft_zoom(&rate, code, v);
		ft_calculate_zoom(&rate, v, new_x, new_y);
	}
	if (code == 2)
	{
		ft_switch(code, v);
	}
	ft_init_fractal(v);
	return (0);
}

int	ft_mouse_move(int x, int y, t_vars *v)
{
	if (v->freeze != 0)
	{
		return (1);
	}
	v->mousex = ft_mapx(x, v);
	v->mousey = ft_mapy(y, v);
	ft_init_fractal(v);
	return (0);
}

int	ft_panel_toggle(int code, t_vars *v)
{
	if (code != 35)
	{
		return (1);
	}
	v->panel = !(v->panel);
	return (0);
}
