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

void	philo_print_pick_up(t_philo *p, int left, int right, int choice)
{
	if (choice == left)
		philo_print_task(p, "has taken the chopstick one the left");
	else if (choice == right)
		philo_print_task(p, "has taken the chopstick one the right");
}

void	philo_print_put_down(t_philo *p, int left, int right, int choice)
{
	if (choice == left)
		philo_print_task(p, "has put down the chopstick one the left");
	else if (choice == right)
		philo_print_task(p, "has put down the chopstick one the right");
}

void	philo_print_task(t_philo *p, char *msg)
{
	long long				idle_time;

	pthread_mutex_lock(& p->table->mtx_print);
	idle_time = ft_current_ms() - p->table->t0;
	if (*msg == 'd')
		printf("%lld\t philo no.%i %s\n", idle_time, p->id, msg);
	else if (*msg == 'e')
		printf("%lld\t %s\n", idle_time, msg);
	else if (!someone_is_dead(p) && !everyone_ate_enough(p))
		printf("%lld\t philo no.%i %s\n", idle_time, p->id, msg);
	pthread_mutex_unlock(& p->table->mtx_print);
}
