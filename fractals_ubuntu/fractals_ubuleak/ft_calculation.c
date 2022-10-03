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

#include "fractal.h"

void	ft_calculate_zoom(double *rate, t_vars *v, int x, int y)
{
	v->mapx = ft_mapx(x, v);
	v->mapy = ft_mapy(y, v);
	v->xrange[0] = ((double)(v->xrange[0] - v->mapx) * *rate) + v->mapx;
	v->yrange[0] = ((double)(v->yrange[0] - v->mapy) * *rate) + v->mapy;
	v->xrange[1] = ((double)(v->xrange[1] - v->mapx) * *rate) + v->mapx;
	v->yrange[1] = ((double)(v->yrange[1] - v->mapy) * *rate) + v->mapy;
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
