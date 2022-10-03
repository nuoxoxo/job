/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/11 08:44:00 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_setup_color(int x, int y, t_vars *v, int i)
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
		v->pix[px + 1] = brightness;
		v->pix[px + 2] = 1;
		v->pix[px + 3] = 1;
		return ;
	}
	v->pix[px + 0] = brightness >> 24;
	v->pix[px + 1] = brightness >> 16;
	v->pix[px + 2] = brightness >> 8;
	v->pix[px + 3] = brightness;
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

/*
void	ft_press_del(int code, t_vars *v)
{
	int	temp;
	int	i;
	int	j;
	int	p;

	if (code ^ 51)	/// ubu 65288
		return ;
	i = -1;
	while (i < v->width)
	{
		j = -1;
		while (j < v->height)
		{
			p = (i + j * v->width) * 4;
			temp = v->pix[p + 0];
			v->pix[p + 0] = v->pix[p + 1];
			v->pix[p + 1] = v->pix[p + 2];
			v->pix[p + 2] = v->pix[p + 3];
			v->pix[3] = temp;
		}
	}
	mlx_put_image_to_window(v->mlx, v->win, v->img, 0, 0);
	ft_panel_show(v);
	ft_printf("(%d) Delete! \n", code);
}
*/
