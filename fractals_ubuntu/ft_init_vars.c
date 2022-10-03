/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/18 13:23:57 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

//	FIXME : v->bound

void	ft_init_vars(t_vars *v)
{
	v->iteration_current = FALSE;
	v->iteration_limit = 256;
	v->bound = v->iteration_limit;
	v->height = 600;
	v->width = 600;
	v->bc = 2;
	v->cx = 0;
	v->cy = 0;
	v->x = 0;
	v->y = 0;
	v->it1 = 0;
	v->it2 = 0;
	v->mapx = 0;
	v->mapy = 0;
	v->mousex = 0;
	v->mousey = 0;
	v->scale = 0.6;
	v->panel = TRUE;
	v->freeze = FALSE;
	v->julia_plot = FALSE;
	v->greyscale = 11;
	v->all_cats_are_grey = FALSE;
	ft_setup_burning_ship_scale(v);
}

void	ft_setup_burning_ship_scale(t_vars *v)
{
	double	factor;

	factor = 1.3;
	if (v->set == 4)
	{
		v->xrange[0] = factor * -2.5;
		v->xrange[1] = factor * 1.0;
		v->yrange[0] = factor * -1.0;
		v->yrange[1] = factor * 1.0;
		return ;
	}
	v->xrange[0] = factor * -2.0;
	v->xrange[1] = factor * 2.0;
	v->yrange[0] = factor * -2.0;
	v->yrange[1] = factor * 2.0;
}

/*	Find c and bc (bionomial coefficient)	*/

void	ft_setup_julia_c(t_vars *v)
{
	if (v->set == 1)
	{
		v->cx = v->mousex;
		v->cy = v->mousey;
		return ;
	}
	v->cx = v->x;
	v->cy = v->y;
}

void	ft_setup_mandelbar_bc(t_vars *v)
{
	if (v->set == 2)
	{
		v->bc = -2;
		return ;
	}
	v->bc = 2;
}
