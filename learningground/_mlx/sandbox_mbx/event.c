#include "mlx/mlx.h"

typedef	struct	s_vars {void *mlx; void *win;}	t_vars;
int	close(int keycode, t_vars *vars);

int	main(void)
{
	t_vars		vars;
	int		width = 960;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, width, "Hello world!");

	mlx_hook(vars.win, 2, 1L << 0, close, &vars);


	//mlx_hook(vars.win, 6, 1L << 4, close, &vars);
	//	not working

	mlx_loop(vars.mlx);
}

/*
 *	Prototype:
 *
 * 	void mlx_hook(
 *			mlx_win_list_t *win_ptr, 
 *			int		x_event,
 *			int		x_mask,
 *			int		(*f)(),
 *			void		*param
 *		)
 *
 *	Example:
 *
 * 	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
 * 	
 *	vars.win	-> window pointer
 *	2		-> hooking event ->	ON_KEYDOWN (keycode 2)
 *	1L << 0		-> X11 mask ->		KeyPressMask
 *
 */


int	close(int keycode, t_vars *vars)
{
	/*
	if (keycode == 9)
		mlx_destroy_window(vars->mlx, vars->win);
	*/
	//	not work

	(void)	keycode;
	mlx_destroy_window(vars->mlx, vars->win);

	return (0);
}
