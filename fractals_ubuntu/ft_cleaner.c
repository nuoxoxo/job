#include "fractal.h"

int	ft_cleaner(t_vars *j)
{
	mlx_destroy_window(j->mlx, j->win);
	mlx_destroy_image(j->mlx, j->img);
	mlx_destroy_display(j->mlx);
	j->win = NULL;
	free(j->mlx);
	return (1);
}
