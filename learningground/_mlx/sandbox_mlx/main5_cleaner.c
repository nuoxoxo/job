#include "mlx/mlx.h"
#include "stdlib.h"

typedef	struct	s_foo
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_foo;

int	ft_cleaner(t_foo *j);

int main(void)
{
	t_foo	j;
	int	S = 256;

	j.mlx = mlx_init();
	if (j.mlx == NULL)
	{
		return (1);
	}

	j.win = mlx_new_window(j.mlx, S, S, "win!");
	if (j.win == NULL)
	{
		return ft_cleaner(&j);
	}

	j.img = mlx_new_image(j.mlx,S,S);
	if (j.img == NULL)
	{
		return ft_cleaner(&j);
	}

	return ft_cleaner(&j);
}

int	ft_cleaner(t_foo *j)
{
	if (!j->mlx)
		return 1;
	if (!j->win)
	{
		free(j->win);
		return 1;
	}
	if (!j->img)
	{
		free(j->img);
	}
	mlx_destroy_window(j->mlx, j->win);
	mlx_destroy_image(j->mlx, j->img);
	mlx_destroy_display(j->mlx);
	j->win = NULL;
	free(j->mlx);
	return 1 ;

}
