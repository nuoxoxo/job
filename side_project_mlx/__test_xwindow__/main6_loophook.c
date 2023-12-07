/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main6_loophook.c                                   :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/11/24 11:30:05 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minilibx-linux/mlx.h"
#include "../mlx/mlx.h"
#include "stdlib.h"

typedef struct s_foo
{
	void	*mlx;
	void	*win;
	void	*img;
}		t_foo;

int	ft_destroy_on_esc(int c, t_foo *_);
int	ft_nothing(int c, t_foo *_);
int	ft_cleaner(t_foo *v);

int	main(void)
{
	t_foo		j;
	int			s;

	s = 512;
	j.mlx = mlx_init();
	if (j.mlx == NULL)
		return (1);
	j.win = mlx_new_window(j.mlx, s, s, "win!");
	if (j.win == NULL)
		return (ft_cleaner(&j));
	j.img = mlx_new_image(j.mlx, s, s);
	if (j.img == NULL)
		return (ft_cleaner(& j));
	mlx_loop_hook(j.mlx, &ft_nothing, & j);
	mlx_key_hook(j.win, &ft_destroy_on_esc, & j);
	mlx_loop(j.mlx);
	mlx_destroy_image(j.mlx, j.img);
//	mlx_destroy_display(j.mlx);
	free(j.mlx);
	return (0);
}

int	ft_destroy_on_esc(int code, t_foo *j)
{
	if (code == 65307)
	{
		mlx_destroy_window(j->mlx, j->win);
		j->win = NULL;
	}
	return (0);
}

int	ft_nothing(int code, t_foo *v)
{
	(void) code;
	(void) v;
	return (0);
}

int	ft_cleaner(t_foo *j)
{
	if (!j->mlx)
		return (1);
	if (!j->win)
	{
		free(j->win);
		return (1);
	}
	if (!j->img)
	{
		free(j->img);
	}
	mlx_destroy_image(j->mlx, j->img);
	mlx_destroy_window(j->mlx, j->win);
//	mlx_destroy_display(j->mlx);
	j->win = NULL;
	free(j->mlx);
	return (1);
}
