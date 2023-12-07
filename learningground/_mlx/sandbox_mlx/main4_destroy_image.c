#include "mlx/mlx.h"
#include "stdlib.h"

#define	MLX_ERR	1
#define	S	1024

int main(void)
{
	void	*win;
	void	*mlx;
	void	*img;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		free(mlx);			/// SR
		return (MLX_ERR);
	}

	win = mlx_new_window(mlx, S, S, "win!");
	if (win == NULL)
	{
		free(win);
		mlx_destroy_display(mlx);	/// SR
		free(mlx);			/// SR
		return (MLX_ERR);
	}

	img = mlx_new_image(mlx,S,S);
	if (img == NULL)		/// SR
	{
		free(img);
		mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
		return (MLX_ERR);
	}

	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
	free(mlx);
}

/*	SR :	seems reasonable to add		*/
