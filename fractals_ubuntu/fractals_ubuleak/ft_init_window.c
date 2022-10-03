/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    :!. .!:         !:.     */
/*   By: nxu <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nxu               :..    ...             */
/*   Updated: 2022/07/07 10:49:45 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_init_window(t_vars *v)
{
	int	bpp;
	int	size_line;
	int	endian;

	v->mlx = mlx_init();
	if (v->mlx == NULL)
	{
		ft_printf("mlx init\n");
		return (1);
	}

	v->win = mlx_new_window(v->mlx, v->width, v->height, "Frak!!");
	if (v->win == NULL)
	{
		ft_printf("new wind");
		mlx_destroy_display(v->mlx);
		free(v->mlx);
		return 1;
	}

	v->img = mlx_new_image(v->mlx, v->width, v->height);
	v->pix = mlx_get_data_addr(v->img, &bpp, &size_line, &endian);

	return 0;
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
