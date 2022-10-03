/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_init_hooks.c                                    :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/07 11:00:48 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_hooks(t_vars *v)
{
	//	mouse move
	//mlx_hook(v->win, 17, 1L << 0, ft_destroy_by_cross, v); // Leak ??
	mlx_hook(v->win, 6, 1L << 6, ft_mouse_move, v);
	mlx_mouse_hook(v->win, ft_mouse_down, v);
	mlx_key_hook(v->win, ft_key_down, v);

	ft_printf("hi from init hooks\n");

	//mlx_loop(v->mlx);
}

/*	not working on ubu ?? FIXME	*/

// mlx_hook(v->win, 6, 0, ft_mouse_move, v);
// mlx_hook(v->win, 4, 0, ft_mouse_down, v);
// mlx_hook(v->win, 2, 0, ft_key_down, v);

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
	if (code == 102)
	{
		ft_freeze(code, v);
	}
	ft_reset(code, v);
	if (code == 32)
	{
		ft_switch(code, v);
	}
	ft_press_g(code, v);
	ft_press_del(code, v);
	
	//ft_init_fractal(v);
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
	if (code == 1)
	{
		ft_freeze(code, v);
	}
	if (code == 4 || code == 5)
	{
		ft_zoom(&rate, code, v);
		ft_calculate_zoom(&rate, v, new_x, new_y);
	}
	if (code == 3)
	{
		ft_switch(code, v);
	}
	ft_init_fractal(v);
	return (0);
}

int	ft_mouse_move(int x, int y, t_vars *v)
{
	if (v->set != 1 || v->freeze != 0)
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
	if (code != 112)
	{
		return (1);
	}
	v->panel = (v->panel + 1) % 2;
	return (0);
}
