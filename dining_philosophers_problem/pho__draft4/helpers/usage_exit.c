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

void	usage_exit(void)
{
	print_cout("\nUsage: ./philo n1 n2 n3 n4 [n5] \n\n");
	print_cout("n1: number of philosophers \n");
	print_cout("n2: time to die (in ms)\n");
	print_cout("n3: time to eat (in ms)\n");
	print_cout("n4: time to sleep (in ms)\n");
	print_cout("n5: (optional) number of meals each one must eat \n");
	print_cout("\n(number of args required: 5 or 6) \n\n");
	exit (0);
}
