/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/07 10:48:00 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_cleaner(t_vars *j)
{
	/*
	if (!j->mlx)
		return 1;
	if (!j->win)
	{
		free(j->mlx);
		return 1;
	}
	if (!j->img)
	{
		//free(j->mlx);
		free(j->win);
	}
	mlx_destroy_window(j->mlx, j->win);
	mlx_destroy_image(j->mlx, j->img);
	mlx_destroy_display(j->mlx);
	j->win = NULL;
	free(j->mlx);
	return 1 ;
	*/
	mlx_destroy_window(j->mlx, j->win);
	mlx_destroy_image(j->mlx, j->img);
	mlx_destroy_display(j->mlx);
	j->win = NULL;
	free(j->mlx);
	return 1 ;

}
