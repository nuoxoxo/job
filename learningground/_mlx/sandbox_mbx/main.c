#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
	int	side = 1080;

	mlx = mlx_init();

	void	*mlx_win;
	mlx_win = mlx_new_window(mlx, side, side, "Hello World!");
	mlx_loop(mlx);

	void	*img;
	img = mlx_new_image(mlx, side, side);
}
