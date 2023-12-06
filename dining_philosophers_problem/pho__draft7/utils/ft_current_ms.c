/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_current_ms(void)
{
	struct timeval		tv;
	long long			second_to_milliseconds;
	long long			micros_to_milliseconds;

	if (gettimeofday(& tv, NULL))
	{
		// exit (1);
		return (-1);
	}
	micros_to_milliseconds = tv.tv_usec / 1000;
	second_to_milliseconds = tv.tv_sec * 1000;
	return (micros_to_milliseconds + second_to_milliseconds);
}
