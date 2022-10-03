/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_ctrl_window.c                                   :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
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

void	ft_destroy(int code, t_vars *v)
{
	if (code ^ 53)
		return ;
	ft_printf("(%d) ESC! \n", code);
	mlx_destroy_window(v->mlx, v->win);
	exit (0);
}

void	ft_freeze(int code, t_vars *v)
{
	if (code ^ 1)
		return ;
	if (v->freeze)
	{
		v->freeze = FALSE;
		ft_printf("(%d) Unfreeze! \n", code);
		return ;
	}
	v->freeze = TRUE;
	ft_printf("(%d) Freeze! \n", code);
}

/*	
 *	below :
 *	
 *	if code is 4 or 38
 * 		~~~>	++(v->iteration_limit);
 *
 *	if code is 5 or 40
 * 		~~~>	--(v->iteration_limit);
 *
 */

void	ft_zoom(double *zoomrate, int code, t_vars *v)
{
	double	arbitrary_rate;

	(void) v;
	ft_printf("(%d) Zoom ", code);
	arbitrary_rate = 0.6;
	if (code == 4 || code == 38)
	{
		*zoomrate = arbitrary_rate;
		ft_printf("in! \n");
	}
	if (code == 5 || code == 40)
	{
		*zoomrate = (double) 1 / arbitrary_rate;
		ft_printf("out! \n");
	}
}

//	toggle on for osx (switch)

void	ft_switch(int code, t_vars *v)
{
	if (code ^ 2 && code ^ 49)
	{
		return ;
	}
	v->set = (v->set + 1) % 4;
	ft_printf("(%d) Switch! \n", code);
}

//	toggle on for linux (switch)

/*
void	ft_next(int code, t_vars *v)
{
	if (code ^ 3 && code ^ 32)
		return ;
	ft_printf("(%d) Switch! \n", code);
	v->type++;
	v->type %= 3;
}
*/

//	toggle on for osx (reset) - [ only w. R and SPACE ]

void	ft_reset(int code, t_vars *v)
{
	if (code ^ 15)
		return ;
	ft_printf("(%d) Reset! \n", code);
	ft_init_vars(v);
}

//	toggle on for linux (reset)

/*
void	ft_reset(int code, t_vars *v)
{
	if (code ^ 2 && code ^ 114)
		return ;
	ft_printf("(%d) Reset! \n", code);
	ft_init_vars(v);
}
*/
