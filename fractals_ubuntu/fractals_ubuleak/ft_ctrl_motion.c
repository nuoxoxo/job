/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_ctrl_motion.c                                   :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/04 11:54:18 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

/*
 *
 * 		126
 * 		65362
 * 		  ^
 *   65361 <		> 65363
 *   123		124
 * 		  v
 * 		65364
 * 		125
 *
 */

/*
 *
 * 		13
 *		119
 *		 W
 *	97 A		D 100
 *	0		2
 * 		 S
 * 		115
 * 		1
 *
 *
 */


void	ft_move_horizontal(int code, t_vars *v)
{
	double	step;

	if (code ^ 97 && code ^ 65361 && code ^ 100 && code ^ 65363)
		return ;
	step = (v->xrange[1] - v->xrange[0]) * 0.1;
	if (code == 97 || code == 65361)
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

	if (code ^ 115 && code ^ 65364 && code ^ 119 && code ^ 65362)
		return ;
	step = (v->yrange[1] - v->yrange[0]) * 0.1;
	if (code == 119 || code == 65362)
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
