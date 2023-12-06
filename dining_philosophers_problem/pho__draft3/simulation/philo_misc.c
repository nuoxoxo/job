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

	if (p->table->flag_of_death)
		return (1);
	diff = ft_current_ms() - p->last_meal;
	if (p->last_meal && (diff > p->table->time_to_die))
	{
		pthread_mutex_lock(& p->table->mutex);
		philo_print_task(p, "is dead");
		p->table->flag_of_death = 1;
		pthread_mutex_unlock(& p->table->mutex);
		return (1);
	}
	return (0);
}

int	is_full(t_philo *p)
{
	int		count;
	int		i;

	if (!p->table->meals)
		return (0);
	count = 0;
	i = -1;
	while (++i < p->table->total_philo)
	{
		if (p->eaten >= p->table->meals)
			count += 1;
	}
	if (count == p->table->total_philo)
	{
		return (1);
	}
	return (0);
}

void	philo_spend_time(t_philo *p, long long n)
{
	long long	start;

	(void) p;
	start = ft_current_ms();
	// while (!is_dead(p) && !is_full(p) && ft_current_ms() - start < n)
	// {
	// 	usleep(100);
	// }
	while (ft_current_ms() - start < n)
	{
		usleep(100);
	}
}

void	philo_print_task(t_philo *p, char *msg)
{
	if (p->table->flag_of_death || is_full(p))
		return ;
	pthread_mutex_lock(& p->table->mutex);
	if (p->table->flag_of_death)
		return ;
	printf("%lld\t . p %d . %s \n",
		ft_current_ms() - p->table->t0, p->id, msg);
	pthread_mutex_unlock(& p->table->mutex);
}

//	prev

/*
void	philo_print_task(t_philo *p, char *msg)
{
	if (p->table->flag_of_death)
		return ;
	if (is_full(p))
		return ;
	printf("%lld\t . p %d . %s \n",
		ft_current_ms() - p->table->t0, p->id, msg);
}
*/