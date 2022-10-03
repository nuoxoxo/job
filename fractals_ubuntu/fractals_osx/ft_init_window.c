/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nxu <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nxu               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nxu              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	ft_init_window(t_vars *v)
{
	int	bpp;
	int	size_line;
	int	endian;

	v->mlx = mlx_init();
	if (!(v->mlx))
	{
		exit (0);
	}
	v->img = mlx_new_image(v->mlx, v->width, v->height);
	v->win = mlx_new_window(v->mlx, v->width, v->height, "Frak!!");
	v->pix = mlx_get_data_addr(v->img, &bpp, &size_line, &endian);
	v->freeze = FALSE;
}

/* 
 *	"Window"
 * 
 *	v->win = mlx_new_window(v->mlx, v->width, v->height, "Frak!!");
 * 
 *	creates a new window instance
 *	return a pointer to this window instance
 *
 */

/*
 *	"Pixels"
 *
 *	v->pix = mlx_get_data_addr(v->img, &bpp, &size_line, &endian);
 *
 *	gets the memory address of the given image
 * 
 */

/*
 *	"MLX Setup"
 *
 *	mlx_init() initializes the mlx library.
 *
 *	must be called before ANY other function.
 *	will return NULL if initialization failed.
 *
 */
