#include "stdlib.h"
#include "mlx/mlx.h"

# define W 512
# define H 512

int main(void)
{
	void	*mlx;
	void	*win;
	int	s = 1024;

	mlx = mlx_init();
	win = mlx_new_window(mlx, s, s, "wind!");
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}
