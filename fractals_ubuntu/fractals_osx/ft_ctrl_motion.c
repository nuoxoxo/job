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

void	ft_move_horizontal(int code, t_vars *v)
{
	double	step;

	if (code && code ^ 2 && code ^ 123 && code ^ 124)
		return ;
	step = (v->xrange[1] - v->xrange[0]) * 0.1;
	if (!code || code == 123)
	{
		v->xrange[0] += step;
		v->xrange[1] += step;
		ft_printf("(%d) Left! \n", code);
		return ;
	}
	v->xrange[0] -= step;
	v->xrange[1] -= step;
	ft_printf("(%d) Right! \n", code);
}

void	ft_move_vertical(int code, t_vars *v)
{
	double	step;

	if (code ^ 1 && code ^ 13 && code ^ 125 && code ^ 126)
		return ;
	step = (v->yrange[1] - v->yrange[0]) * 0.1;
	if (code == 13 || code == 126)
	{
		v->yrange[0] += step;
		v->yrange[1] += step;
		ft_printf("(%d) Up! \n", code);
		return ;
	}
	v->yrange[0] -= step;
	v->yrange[1] -= step;
	ft_printf("(%d) Down! \n", code);
}
