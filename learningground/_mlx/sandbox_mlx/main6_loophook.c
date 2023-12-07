#include "mlx/mlx.h"
#include "stdlib.h"

typedef	struct	s_foo
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_foo;

int	ft_destroy_on_esc(int code, t_foo *v);
int	ft_nothing(int code, t_foo *v);
int	ft_cleaner(t_foo *v);

int	main()
{
	t_foo		j;
	int		S = 1024;

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

	mlx_loop_hook(j.mlx, &ft_nothing, &j);	/* LOOP Hook */

	mlx_key_hook(j.win, &ft_destroy_on_esc, &j);		/* Hook */
	//mlx_hook(j.mlx, 2, 1L << 0, &ft_destroy_on_esc, &j);	/* Leak */

	mlx_loop(j.mlx);			/* LOOP */

	///	no leaks with this not with cleaner
	mlx_destroy_image(j.mlx, j.img);	/* FREE */
	mlx_destroy_display(j.mlx);
	free(j.mlx);

	return (0) ;
}

int	ft_destroy_on_esc(int code, t_foo *j)
{
	(void)	j;
	if (code == 65307)
	{
		mlx_destroy_window(j->mlx, j->win);
		j->win = NULL;
	}
	return (0) ;
}

int	ft_nothing(int code, t_foo *v)
{
	(void)		code;
	(void)		v;

	return 0 ;
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
	mlx_destroy_image(j->mlx, j->img);
	mlx_destroy_window(j->mlx, j->win);
	mlx_destroy_display(j->mlx);
	j->win = NULL;
	free(j->mlx);
	return (1) ;
}
