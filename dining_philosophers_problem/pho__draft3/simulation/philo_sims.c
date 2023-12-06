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

void	simulation_initialize(t_philo *philo, t_table *table)
{
	int			i;
	t_philo		*p;

	if (pthread_mutex_init(& table->mutex, NULL))
		clean_exit(philo, table, 1);
	i = -1;
	while (++i < table->total_philo)
	{
		p = & philo[i];
		p->table = table;
		if (pthread_create(& p->thread, NULL, philo_routine, p))
			clean_exit(philo, table, 1);
	}
	i = -1;
	while (++i < table->total_philo)
	{
		if (pthread_mutex_init(& table->chops[i], NULL))
			clean_exit(philo, table, 1);
	}
}

void	simulation_jointhread(t_philo *philo, t_table *table)
{
	int		i;

	i = -1;
	while (++i < table->total_philo)
	{
		print("here \n");
		if (pthread_join(philo[i].thread, NULL))
			clean_exit(philo, table, 1);
	}
	i = -1;
	while (++i < table->total_philo)
	{
		if (pthread_mutex_destroy(& table->chops[i]))
			clean_exit(philo, table, 1);
	}
	if (pthread_mutex_destroy(& table->mutex))
		clean_exit(philo, table, 1);
}

void	*philo_routine(void *tmp)
{
	t_philo		*p;

	p = (t_philo *) tmp;
	while (!is_dead(p) && !is_full(p))
	{
		philo_eat(p);
		philo_sleep(p);
		philo_think(p);
	}
	return (NULL);
}
