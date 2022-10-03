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

int	end_is_nigh(t_philo *p)
{
	if (!is_dead(p) && !is_full(p))
		return (0);
	return (1);
}

int	is_dead(t_philo *p)
{
	int		diff;

	// pthread_mutex_lock(& p->table->mtx_death);
	// if (p->table->flag_of_death)
	// {
	// 	pthread_mutex_unlock(& p->table->mtx_death);
	// 	return (1);
	// }
	// diff = ft_current_ms() - p->last_meal;
	// if (p->last_meal && (diff > p->table->time_to_die))
	// {
	// 	pthread_mutex_lock(& p->table->mtx_death);

	// 	philo_print_task(p, "is dead");
	// 	p->table->flag_of_death = 1;
	// 	pthread_mutex_unlock(& p->table->mtx_death);
	// 	return (1);
	// }
	// pthread_mutex_unlock(& p->table->mtx_death);
	// return (0);

	/*	Different unlocking sequence . No flag_o_death check	*/

	diff = ft_current_ms() - p->last_meal;
	if (p->last_meal && diff > p->table->time_to_die)
	{
		pthread_mutex_lock(& p->table->mtx_death);
		p->table->flag_of_death = 1;
		philo_print_task(p, "is dead");
		pthread_mutex_unlock(& p->table->mtx_death);
		return (1);
	}
	return (0);
}

int	is_full(t_philo *p)
{
	int		count;
	int		i;

	if (! (p->table->meals))
		return (0);
	count = 0;
	i = -1;
	while (++i < p->table->total_philo)
	{
		if (p->eaten >= p->table->meals)
			count += 1;
	}
	if (count == p->table->total_philo)
		return (1);
	return (0);
}

void	philo_spend_time(t_philo *p, long long n)
{
	long long	start;

	(void) p;
	start = ft_current_ms();
	while (!end_is_nigh(p) && ft_current_ms() - start < n)
		usleep(400);
}

void	philo_print_task(t_philo *p, char *msg)
{
	long long				idle_time;

	pthread_mutex_lock(& p->table->mtx_print);
	// if (p->table->flag_of_death || is_full(p)) // absence of state check
	if (end_is_nigh_again(p))// introduce state check
	{
		pthread_mutex_unlock(& p->table->mtx_print);
		return ;
	}
	idle_time = ft_current_ms() - p->table->t0;
	printf("%lld\t . p %d . %s \n", idle_time, p->id, msg);
	pthread_mutex_unlock(& p->table->mtx_print);
}

int	end_is_nigh_again(t_philo *p)
{
	static int		ret;

	pthread_mutex_lock(& p->table->mtx_anyone_can_use);
	if (ret)
	{
		pthread_mutex_unlock(& p->table->mtx_anyone_can_use);
		return (ret);
	}
	pthread_mutex_unlock(& p->table->mtx_anyone_can_use);
	if (p->table->flag_of_death)
	{
		pthread_mutex_lock(& p->table->mtx_anyone_can_use);
		ret++;
		pthread_mutex_unlock(& p->table->mtx_anyone_can_use);
	}
	else if (is_full(p))
		return (1);
	return (0);
}
