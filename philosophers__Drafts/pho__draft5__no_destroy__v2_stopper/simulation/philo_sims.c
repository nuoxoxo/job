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

void	*philo_routine(void *tmp)
{
	t_philo		*p;

	p = (t_philo *) tmp;
	while (!is_dead(p) && !is_full(p))
	{
		philo_eat(p);
		philo_sleep_and_think(p);
	}
	return (NULL);
}

void	simulation_initialize(t_philo *philo, t_table *table)
{
	int			i;
	t_philo		*p;

	if (pthread_mutex_init(& table->mtx_print, NULL))
		exit (1);
		// clean_exit(philo, table, 1);
	if (pthread_mutex_init(& table->mtx_death, NULL))
		exit (1);
		// clean_exit(philo, table, 1);
	i = -1;
	while (++i < table->total_philo)
	{
		if (pthread_mutex_init(& table->chops[i], NULL))
			exit (1);
			// clean_exit(philo, table, 1);
		p = & philo[i];
		p->table = table;
		if (pthread_create(& p->thread, NULL, philo_routine, p))
			exit (1);
			// clean_exit(philo, table, 1);
	}
}

void	simulation_jointhread(t_philo *philo, t_table *table)
{
	int		i;

	i = -1;
	while (++i < table->total_philo)
	{
		if (pthread_join(philo[i].thread, NULL))
			exit (1);
			clean_exit(philo, table, 1);
	}

	/*	TRY fixing data race : No destroy anywhere	*/

	// i = -1;
	// while (++i < table->total_philo)
	// {
	// 	if (pthread_mutex_destroy(& table->chops[i]))
	// 		clean_exit(philo, table, 1);
	// }
	// if (pthread_mutex_destroy(& table->mtx_death))
	// 	clean_exit(philo, table, 1);
	// if (pthread_mutex_destroy(& table->mtx_print))
	// 	clean_exit(philo, table, 1);
}

void	simulation_destroyall(t_table *t) // New in draft5.2
{
	int				i;

	i = -1;
	while (++i < t->total_philo)
	{
		pthread_mutex_destroy(& t->chops[i]);
	}
	pthread_mutex_destroy(& t->mtx_death);
	pthread_mutex_destroy(& t->mtx_print);
}

/*
 	pthread_mutex_t	*chops;
	pthread_mutex_t	mtx_death;
	pthread_mutex_t	mtx_print;
*/