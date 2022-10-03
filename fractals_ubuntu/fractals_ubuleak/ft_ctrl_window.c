/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_ctrl_window.c                                   :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/07 10:57:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/* 	motions	include	*/

/*
 * 	freeze
 *	zoom
 *	reset
 *	next
 *	destroy
 *
 */

/* 	try to free properly before every type of exit	*/

int 	ft_destroy_by_cross(t_vars *v)
{
	/*
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_display(v->mlx);
	v->win = NULL;
	exit (0);
	*/

	//mlx_destroy_window(v->mlx, v->win);
	ft_destroy(65407, v);
	//v->win = NULL;
	return (0) ;
}

//void	ft_destroy(int code, t_vars *v)
int	ft_destroy(int code, t_vars *v)
{
	if (code ^ 65307)
		return (1);
	ft_printf("(%d) ESC! \n", code);
	
	/*
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_display(v->mlx);
	v->win = NULL;
	//exit (0);
	*/
	
	/*
	if (v->img)
		mlx_destroy_image(v->mlx, v->img);
	if (v->win)
	{
		mmlx_destroy_window(v->mlx, )
		return 1;
	}
	mlx_destroy_image(v->mlx, v->img);
	mlx_destroy_window(v->mlx, v->win);
	mlx_destroy_display(v->mlx);
	v->win = NULL;
	free(v->mlx);
	*/
	mlx_destroy_window(v->mlx, v->win);
	v->win = NULL;
	return (0);
}

void	ft_freeze(int code, t_vars *v)
{
	if (code ^ 1 && code ^ 102)
		return ;
	if (v->freeze == 1)
	{
		v->freeze = 0;
		ft_printf("(%d) Unfreeze! \n", code);
		return ;
	}
	v->freeze = 1;
	ft_printf("(%d) Freeze! \n", code);
}

/*	
 *	below :
 *	
 *	if code is WHEEL_UP
 * 		~~~>	++(v->iteration_limit);
 *
 *	if code is WHEEL_DOWN
 * 		~~~>	--(v->iteration_limit);
 *
 */

void	ft_zoom(double *zoomrate, int code, t_vars *v)
{
	double	arbitrary_rate;

	(void) v;
	ft_printf("(%d) Zoom ", code);
	arbitrary_rate = 0.6;
	if (code == 4)
	{
		*zoomrate = arbitrary_rate;
		ft_printf("in! \n");
	}
	if (code == 5)
	{
		*zoomrate = (double) 1 / arbitrary_rate;
		ft_printf("out! \n");
	}
}

//	toggle on for osx (switch)
/*
void	ft_switch(int code, t_vars *v)
{
	if (code ^ 2 && code ^ 49)
	{
		return ;
	}
	v->set = (v->set + 1) % 4;
	ft_printf("(%d) Switch! \n", code);
}
*/

//	toggle on for linux (switch)

void	ft_switch(int code, t_vars *v)
{
	int	space;

	space = 32;
	if (code ^ space && code ^ 3)
	{
		return ;
	}
	ft_printf("(%d) Switch! \n", code);
	v->set++;
	v->set %= 4;
}

//	toggle on for osx (reset) - [ only w. R and SPACE ]
/*
void	ft_reset(int code, t_vars *v)
{
	if (code ^ 15)
		return ;
	ft_printf("(%d) Reset! \n", code);
	ft_init_vars(v);
}

//	toggle on for linux (reset)
*/

void	ft_reset(int code, t_vars *v)
{
	if (code ^ 2 && code ^ 114)
	{
		return ;
	}
	ft_printf("(%d) Reset! \n", code);
	ft_init_vars(v);
}
