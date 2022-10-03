/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/07 11:08:19 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_parser2(const char *m, const char *n, t_vars *_);
int		ft_parser1(const char *s, t_vars *_);
void	ft_prompt(void);

int	main(int c, const char **v)
{
	t_vars	vs;

	if (c - 2 < 0 || c - 3 > 0
		|| (c == 2 && ft_parser1(v[1], & vs))
		|| (c == 3 && ft_parser2(v[1], v[2], & vs)))
	{
		ft_prompt();
	}

	ft_init_vars(& vs);
	//ft_printf("hh");

	if (ft_init_window(& vs)) //	seems OK
		return (1);
	ft_printf("break here\n");

	mlx_loop_hook(vs.mlx, & ft_init_fractal, & vs);

	ft_init_hooks(& vs);

	mlx_loop(vs.mlx);

	//ft_init_fractal(& vs);

	//ft_init_hooks(& vs);
	//mlx_loop(vs.mlx);

	/*
	vs.freeze = FALSE;
	mlx_loop_hook(vs.mlx, ft_init_fractal, & vs);
	ft_init_hooks(& vs);
	mlx_loop(vs.mlx);
	mlx_destroy_image(vs.mlx, vs.img);
	mlx_destroy_display(vs.mlx);
	free(vs.mlx);
	*/


	//return (0);
	ft_printf("hi from main.\n");
	mlx_destroy_image(vs.mlx, vs.img);
	mlx_destroy_display(vs.mlx);
	free(vs.mlx);

	return (0);
}

//

void	ft_prompt(void)
{
	ft_putstr("Usage: ./fractol [ ");
	ft_putstr("mandelbrot | mandelbar | tricorn | julia | burning ship");
	ft_putstr(" ] \n");
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
