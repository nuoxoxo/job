/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nuo              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	ft_panel_toggle(int code, t_vars *v)
{
	if (code != 112)
	{
		return (1);
	}
	v->panel = (v->panel + 1) % 2;
	return (0);
}

int	ft_panel_show(t_vars *v)
{
	int	x;

	x = 32;
	if (!(v->panel))
		return (1);
	mlx_string_put(v->mlx, v->win, x, x + 0, 0x2DFFFF, "CONTROL:");
	mlx_string_put(v->mlx, v->win, x, x + 40, 0xFFFFFF, "Move = w a s d");
	mlx_string_put(v->mlx, v->win, x, x + 60, 0xFFFFFF, "Move = ^ < v >");
	mlx_string_put(v->mlx, v->win, x, x + 80, 0xFFFFFF, "Zoom = Wheel");
	mlx_string_put(v->mlx, v->win,
		x, x + 100, 0xFFFFFF, "Switch = Mouse R");
	mlx_string_put(v->mlx, v->win, x, x + 120, -1, "Freeze = Mouse L");
	mlx_string_put(v->mlx, v->win, x, x + 140, 0xFFFFFF, "Reset = R");
	mlx_string_put(v->mlx, v->win, x, x + 160, 0xFFFFFF, "Panel = P");
	mlx_string_put(v->mlx, v->win, x, x + 180, 0xFFFFFF, "Quit = ESC");
	return (0);
}
