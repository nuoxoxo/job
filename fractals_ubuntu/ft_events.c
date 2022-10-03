/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2022/07/15 09:21:43 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

#include "math.h"

int	ft_destroy(int code, t_vars *v)
{
	if (code ^ 65307 && code ^ 65407)
		return (1);
	ft_printf("(%d) ESC! \n", code);
	ft_cleaner(v);
	exit (0);
	return (0);
}

void	ft_freeze(int code, t_vars *v)
{
	if (code ^ 1 && code ^ 102)
		return ;
	if (v->freeze == 1)
	{
		v->freeze = 0;
		ft_printf("(%d) Unfreeze! \n", code);
		return ;
	}
	v->freeze = 1;
	ft_printf("(%d) Freeze! \n", code);
}

void	ft_zoom(int code, t_vars *v)
{
	double		arbitrary_rate;

	(void) v;
	arbitrary_rate = 0.8;
	ft_printf("(%d) Zoom ", code);
	if (code == 4)
	{
		v->scale = arbitrary_rate;
		v->iteration_limit++;
		v->iteration_limit = (int) \
			2 * \
			(sqrt(2 * sqrt(abs(1 - (int) sqrt(5 * v->scale)))) \
			* 66.5);
		ft_printf("in! \n");
	}
	if (code == 5)
	{
		v->scale = (double) 1 / arbitrary_rate;
		v->iteration_limit--;
		ft_printf("out! \n");
	}
}

/*	Above `v->it_lim--` can be replaced by	*/

/*	
v->iteration_limit -= (int)
(sqrt(2 * sqrt(abs(1 - (int) sqrt(5 * v->scale)))) * 66.5);
*/

void	ft_switch(int code, t_vars *v)
{
	int	space;

	space = 32;
	if (code ^ space && code ^ 3)
	{
		return ;
	}
	ft_printf("(%d) Switch! \n", code);
	v->set++;
	v->set %= 4;
}

void	ft_reset(int code, t_vars *v)
{
	if (code ^ 2 && code ^ 114)
	{
		return ;
	}
	ft_printf("(%d) Reset! \n", code);
	ft_init_vars(v);
}
