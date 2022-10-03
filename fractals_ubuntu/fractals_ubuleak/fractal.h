/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/07 08:54:19 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx/mlx.h"
# include "unistd.h"
# include "stdlib.h" // exit(int _)

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s__
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pix;
	double	xrange[2];
	double	yrange[2];
	double	mousex;
	double	mousey;
	double	x;
	double	y;
	double	cx;
	double	cy;
	double	mapx;
	double	mapy;
	int		iteration_current;
	int		iteration_limit;
	int		height;
	int		width;
	int		it1;
	int		it2;
	int		bc;
	int		set;
	int		panel;
	int		bound;
	int		freeze;
	int		greyscale;
	int		all_cats_are_grey;
}			t_vars;

double	ft_mapx(int coordinate, t_vars *v);
double	ft_mapy(int coordinate, t_vars *v);
void	ft_calculate_zoom(double *_, t_vars *v, int x, int y);
void	ft_calculate_bc(t_vars *_);
void	ft_calculate_c(t_vars *_);
int	ft_init_window(t_vars *_);
//void	ft_init_window(t_vars *_);
void	ft_init_vars(t_vars *_);
void	ft_init_hooks(t_vars *_);
int	ft_init_fractal(t_vars *_);
//void	ft_init_fractal(t_vars *_);
void	ft_loop_fractol(t_vars *_);
void	ft_move_vertical(int c, t_vars *_);
void	ft_move_horizontal(int c, t_vars *v);
void	ft_setup_burning_ship_scale(t_vars *v);
void	ft_setup_mandelbar_bc(t_vars *v);
void	ft_setup_julia_c(t_vars *v);
void	ft_press_del(int c, t_vars *_);
void	ft_press_g(int c, t_vars *_);
void	ft_freeze(int c, t_vars *_);
void	ft_reset(int c, t_vars *_);
void	ft_zoom(double *_, int c, t_vars *v);
void	ft_pixel(int x, int y, t_vars *v, int n);
void	ft_switch(int code, t_vars *_);
//void	ft_destroy(int c, t_vars *_);
int	ft_destroy(int c, t_vars *_);
void	ft_putstr(char const *s);
int		ft_destroy_by_cross(t_vars *_);
int		ft_mouse_down(int c, int x, int y, t_vars *v);
int		ft_mouse_move(int x, int y, t_vars *v);
int		ft_panel_toggle(int code, t_vars *v);
int		ft_panel_show(t_vars *v);
int		ft_key_down(int c, t_vars *v);
int		ft_strcmp(const char *_, const char *__);
int		ft_printf(const char *_, ...);
int		ft_printf(const char *_, ...);
int		ft_cleaner(t_vars* _);

#endif
