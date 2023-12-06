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

int	is_dead(t_philo *p)
{
	int		diff;

	pthread_mutex_lock(& p->table->mtx_death);
	if (p->table->flag_of_death)
	{
		pthread_mutex_unlock(& p->table->mtx_death);
		return (1);
	}
	diff = ft_current_ms() - p->last_meal;
	if (p->last_meal && (diff > p->table->time_to_die))
	{
		philo_print_task(p, "is dead");
		p->table->flag_of_death = 1;
		pthread_mutex_unlock(& p->table->mtx_death);
		return (1);
	}
	pthread_mutex_unlock(& p->table->mtx_death);
	return (0);
}

// int	is_full(t_philo *p)
// {
// 	int		count;
// 	int		i;

// 	if (!p->table->meals)
// 		return (0);
// 	count = 0;
// 	i = -1;
// 	while (++i < p->table->total_philo)
// 	{
// 		if (p->eaten >= p->table->meals)
// 			count += 1;
// 	}
// 	if (count == p->table->total_philo)
// 		return (1);
// 	return (0);
// }

int	is_full(t_philo *philo)
{
	int	i;
	int	count;
	int	meals;

	if (! philo->table->meals)
		return (0);
	i = -1;
	count = 0;
	while (++i < philo->table->total_philo)
	{
		pthread_mutex_lock(& philo->table->mutex_full);
		meals = philo[i].eaten;
		pthread_mutex_unlock(& philo->table->mutex_full);
		if (meals >= philo->table->meals)
			if (++count == philo->table->total_philo)
				return (1);
	}
	return (0);
}

void	philo_spend_time(t_philo *p, long long n)
{
	long long	start;

	(void) p;
	start = ft_current_ms();
	while (!is_dead(p) && !is_full(p) && ft_current_ms() - start < n)
		usleep(90); // seems like we have to sleep
}

void	philo_print_task(t_philo *p, char *msg)
{
	pthread_mutex_lock(& p->table->mtx_print);
	if (p->table->flag_of_death || is_full(p))
	{
		pthread_mutex_unlock(& p->table->mtx_print);
		return ;
	}
	printf("%lld\t . p %d . %s \n",
		ft_current_ms() - p->table->t0, p->id, msg);
	pthread_mutex_unlock(& p->table->mtx_print);
}
