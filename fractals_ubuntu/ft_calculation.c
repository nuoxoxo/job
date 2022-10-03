/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_calculation.c                                   :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/07 12:28:20 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_calculate_zoom(t_vars *v, int x, int y)
{
	double	dx_start;
	double	dy_start;
	double	dx_end;
	double	dy_end;

	v->mapx = ft_mapx(x, v);
	v->mapy = ft_mapy(y, v);
	dx_start = (double)(v->xrange[0] - v->mapx);
	dy_start = (double)(v->yrange[0] - v->mapy);
	dx_end = (double)(v->xrange[1] - v->mapx);
	dy_end = (double)(v->yrange[1] - v->mapy);
	v->xrange[0] = (dx_start * v->scale) + v->mapx;
	v->yrange[0] = (dy_start * v->scale) + v->mapy;
	v->xrange[1] = (dx_end * v->scale) + v->mapx;
	v->yrange[1] = (dy_end * v->scale) + v->mapy;
}

/*
 * 	implement [p5js]'s map() function:
 *
 *	map(value, start1, end1, start2, end2);
 */

double	ft_mapx(int x, t_vars *v)
{
	double	d;
	double	r;

	d = v->xrange[1] - v->xrange[0];
	r = d / v->width;
	return (v->xrange[0] + r * x);
}

double	ft_mapy(int y, t_vars *v)
{
	double	d;
	double	r;

	d = v->yrange[1] - v->yrange[0];
	r = d / v->height;
	return (v->yrange[0] + (r * y));
}
