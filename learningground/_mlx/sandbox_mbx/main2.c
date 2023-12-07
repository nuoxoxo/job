#include "mlx/mlx.h"

typedef struct	s_data
{
	char	*addr;
	void	*img;
	int	bpp;	// bits per pixel
	int	line_len;
	int	endian;
}		t_data;

void	alt_mlx_pixel_put(t_data *d, int a, int b, int _);

int	main(void)
{
	t_data		img;
	void		*mlx;
	void		*mlx_win;
	int		side = 512;
	int		color = 0xff8bc34a;
	int		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, side, side, "Hello, World!");

	img.img = mlx_new_image(mlx, side, side);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);

	i = side % 2 + 2;
	while (i < side)
	{

		alt_mlx_pixel_put(&img, i, i, color * i % 256);
		alt_mlx_pixel_put(&img, side - i, side - i, color * i % 256);
		alt_mlx_pixel_put(&img, i, side - i, color * i % 256);
		alt_mlx_pixel_put(&img, side - i, i, color * i % 256);
		i *= 5;
		i /= 3;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 128, 128);
	mlx_loop(mlx);
}

void	alt_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dist;
	int	dx = x * (data->bpp / 8);
	int	dy = y * data->line_len;

	dist = data->addr + dx + dy;
	*(unsigned int*) dist = color;
}
