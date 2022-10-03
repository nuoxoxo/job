/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   showkey.c                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/15 11:21:05 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../minilibx-linux/mlx.h"
#include "../mlx/mlx.h"
#include "stdlib.h"
#include "stdio.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}		t_vars;

int	mouse_hook(int c, t_vars *_);
int	key_hook(int c, t_vars *_);
int	close(int c, t_vars *_);

int	main(void)
{
	int		wide;
	t_vars	v;

	wide = 960;
	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, wide, wide, "Hello, World!");
	mlx_key_hook(v.win, key_hook, & v);
	mlx_mouse_hook(v.win, mouse_hook, & v);
	mlx_loop(v.mlx);
}

int	mouse_hook(int c, t_vars *vars)
{
	if (c == 1)
		printf("Left click! (%d) \n", c);
	else if (c == 2)
		printf("Wheel says \"Hi!\" (%d) \n", c);
	else if (c == 3)
		printf("Right click! (%d) \n", c);
	else if (c == 4)
		printf("Wheel up (%d) \n", c);
	else if (c == 5)
		printf("Wheel down (%d) \n", c);
	else
		printf("Clicked! mousecode: %d \n", c);
	(void) vars;
	return (0);
}

int	key_hook(int c, t_vars *v)
{
	int	zero;

	zero = 48;
	if (c == zero)
		printf("Zero (%d) \n", c);
	else if (c < 58 && c > zero)
		printf("%d (%d) \n", c - zero, c);
	else if (c == 65361)
		printf("Left! (%d) \n", c);
	else if (c == 65362)
		printf("Up! (%d) \n", c);
	else if (c == 65363)
		printf("Right! (%d) \n", c);
	else if (c == 65364)
		printf("Down! (%d) \n", c);
	else if (c == 65307)
		close(c, v);
	else
		printf("Keydown! keycode: %d \n", c);
	return (0);
}

int	close(int keycode, t_vars *v)
{
	if (keycode == 65307)
	{
		printf("ESC! (%d) \n", keycode);
		mlx_destroy_window(v->mlx, v->win);
		mlx_destroy_display(v->mlx);
		v->win = NULL;
		free(v->mlx);
		exit (0);
	}
	return (0);
}
