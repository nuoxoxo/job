/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/18 13:22:25 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_parser2(const char *m, const char *n, t_vars *_);
int		ft_parser1(const char *s, t_vars *_);
//void	ft_prompt(void);

//	FIXME	-	Compare two main for speed

int	main(int c, const char **v)
{
	t_vars	vars;

	if (c < 2 || c > 4 || (c == 2 && ft_parser1(v[1], & vars))
		|| (c == 3 && ft_parser2(v[1], v[2], & vars)))
		ft_prompt();
	if (c == 4)
		ft_init_julia(v[2], v[3], & vars);
	else
		ft_init_vars(& vars);
	if (ft_init_window(& vars))
		return (1);
	ft_init_fractal(& vars);
	if (!vars.julia_plot)
	{
		ft_init_hooks(& vars);
	}
	else
	{
		mlx_loop_hook(vars.mlx, NULL, & vars);
		mlx_hook(vars.win, 17, 0L, & ft_destroy_by_cross, &vars);
		mlx_key_hook(vars.win, & ft_destroy, &vars);
	}
	mlx_loop(vars.mlx);
	ft_cleaner(& vars);
	return (0);
}

//	helpers

void	ft_prompt(void)
{
	ft_putstr("Usage: \n./fractol [ ");
	ft_putstr("mandelbrot | mandelbar | tricorn | julia | burning ship");
	ft_putstr(" ] \n");
	ft_putstr("or \n./fractol julia coordinate_1 coordinate_2 \n");
	exit (0);
}

int	ft_parser2(const char *s1, const char *s2, t_vars *v)
{
	if (!ft_strcmp(s1, "burning") && !ft_strcmp(s2, "ship"))
	{
		v->set = 3;
		return (0);
	}
	return (1e3);
}

int	ft_parser1(const char *s, t_vars *v)
{
	if (!ft_strcmp(s, "mandelbrot") || \
		! ft_strcmp(s, "man") || !ft_strcmp(s, "1"))
	{
		v->set = 0;
		return (0);
	}
	if (! ft_strcmp(s, "julia") || \
		!ft_strcmp(s, "jul") || !ft_strcmp(s, "2"))
	{
		v->set = 1;
		return (0);
	}
	if (!ft_strcmp(s, "mandelbar") || !ft_strcmp(s, "3") || \
		! ft_strcmp(s, "tri") || ! ft_strcmp(s, "tricorn"))
	{
		v->set = 2;
		return (0);
	}
	if (!ft_strcmp(s, "burning ship") || \
		!ft_strcmp(s, "burn") || !ft_strcmp(s, "4"))
	{
		v->set = 3;
		return (0);
	}
	return (1e3);
}

/*
int	main(int c, const char **v)
{
	t_vars	vars;

	if (c - 2 < 0 || c - 3 > 0
		|| (c == 2 && ft_parser1(v[1], & vars))
		|| (c == 3 && ft_parser2(v[1], v[2], & vars)))
	{
		ft_prompt();
	}
	ft_init_vars(& vars);
	vars.freeze = FALSE;
	if (ft_init_window(& vars))
		return (1);
	ft_printf("Hi from upper main\n");
	ft_looper(& vars);
	ft_printf("Hi from downtown.\n");
	mlx_destroy_image(vars.mlx, vars.img);
	vars.img = NULL;
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
	vars.mlx = NULL;
	return (0);
}
*/
