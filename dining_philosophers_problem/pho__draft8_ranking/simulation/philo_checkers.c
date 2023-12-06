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

int	everyone_ate_enough(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->mtx_close);
	if (philo->table->flag_of_close)
	{
		pthread_mutex_unlock(&philo->table->mtx_close);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->mtx_close);
	return (0);
}

int	someone_is_dead(t_philo *philo)
{
	pthread_mutex_lock(& philo->table->mtx_death);
	if (philo->table->flag_of_death)
	{
		pthread_mutex_unlock(& philo->table->mtx_death);
		return (1);
	}
	pthread_mutex_unlock(& philo->table->mtx_death);
	return (0);
}

void	set_flag_of_death(t_table *table)
{
	pthread_mutex_lock(&table->mtx_death);
	table->flag_of_death = 1;
	pthread_mutex_unlock(&table->mtx_death);
}

void	set_flag_of_close(t_table *table)
{
	pthread_mutex_lock(&table->mtx_close);
	table->flag_of_close = 1;
	pthread_mutex_unlock(&table->mtx_close);
}

int	check_if_all_ate_enough(t_philo *philo, t_table *table)
{
	int	i;
	int	total;
	int	meals_count;

	if (table->meals < 0)
		return (0);
	i = -1;
	total = 0;
	while (++i < table->total_philo)
	{
		pthread_mutex_lock(&philo->table->mtx_meals);
		meals_count = philo[i].eaten;
		pthread_mutex_unlock(&philo->table->mtx_meals);
		if (meals_count >= table->meals)
			if (++total == table->total_philo)
				return (1);
	}
	return (0);
}
