#include "mlx/mlx.h"
#include "stdlib.h"

#define	MLX_ERR	1
#define	S	512

int main(void)
{
	void	*wind;
	void	*mlx;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		return (MLX_ERR);
	}

	wind = mlx_new_window(mlx, S, S, "wind!");
	if (wind == NULL)
	{
		free(wind);
		return (MLX_ERR);
	}

	mlx_destroy_window(mlx, wind);
	mlx_destroy_display(mlx);

	free(mlx);
}
