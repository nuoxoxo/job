/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_ctrl_colors.c                                   :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/04 11:38:03 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_pixel(int x, int y, t_vars *v, int i)
{
	int		px;
	char	brightness;

	if (i > v->bound - 1)
	{
		brightness = 1;
	}
	else
	{
		brightness = i * v->greyscale % 255;
	}
	px = (x + y * v->width) * 4;
	if (!v->all_cats_are_grey)
	{
		v->pix[px + 0] = 24 * brightness;
		v->pix[px + 1] = 16 + brightness;
		v->pix[px + 2] = 8 + brightness;
		v->pix[px + 3] = 0;
		return ;
	}
	v->pix[px + 0] = brightness >> 24;
	v->pix[px + 1] = brightness >> 16;
	v->pix[px + 2] = brightness >> 8;
	v->pix[px + 3] = 0;
}

/*
 * pixel array [0]: B
 * pixel array [1]: G
 * pixel array [2]: R
 * pixel array [3]: t
 *
 */

void	ft_press_g(int code, t_vars *v)
{
	if (code ^ 103)
		return ;
	v->all_cats_are_grey = !v->all_cats_are_grey;
}

void	ft_press_del(int code, t_vars *v)
{
	if (code ^ 65288)
		return ;
	v->greyscale %= 255;
	v->greyscale++;
	ft_printf("(%d) Delete! \n", code);
}
