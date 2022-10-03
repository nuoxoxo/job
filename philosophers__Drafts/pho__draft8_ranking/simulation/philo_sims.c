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

void	*philo_routine(void *philo)
{
	t_philo				*p;

	p = (t_philo *) philo;
	if (p->id % 2 == 0)
	{
		philo_print_task(p, "is thinking");
		philo_pass_time(p, p->table->time_to_eat);
	}
	while (1)
	{
		if (someone_is_dead(p))
			break ;
		if (everyone_ate_enough(p))
			break ;
		if (! philo_eat(p))
			break ;
		philo_print_task(p, "is sleeping");
		philo_pass_time(p, p->table->time_to_sleep);
		philo_print_task(p, "is thinking");
		if (p->table->time_to_eat > p->table->time_to_sleep)
			philo_pass_time(p, p->table->time_to_eat - p->table->time_to_sleep);
		// del. line that incl. +1
	}
	return (NULL);
}

/*
	table mtx to free:

	pthread_mutex_t		mtx_death; // set Death flag
	pthread_mutex_t		mtx_print;
	pthread_mutex_t		mtx_meals; // count meals
	pthread_mutex_t		mtx_close; // set Close flag

*/

void	simulation_init_all_mutex(t_philo *philo, t_table *table)
{
	int				i;

	if (pthread_mutex_init(& table->mtx_death, NULL))
		clean_exit(philo, table, 1);
	if (pthread_mutex_init(& table->mtx_print, NULL))
		clean_exit(philo, table, 1);
	if (pthread_mutex_init(& table->mtx_meals, NULL))
		clean_exit(philo, table, 1);
	if (pthread_mutex_init(& table->mtx_close, NULL))
		clean_exit(philo, table, 1);
	i = -1;
	while (++i < table->total_philo)
		if (pthread_mutex_init (& philo[i].chops[i], NULL))
			clean_exit(philo, table, 1);
}

void	simulation_launch_routine(t_philo *p, t_table *t, pthread_t *paths)
{
	int				i;

	i = -1;
	while (++i < t->total_philo)
	{
		if (pthread_create(& paths[i], NULL, philo_routine, & p[i]))
		{
			while (i--)
				pthread_join(paths[i], NULL);
			free(paths);
			clean_exit(p, t, 1);
		}
	}
}

void	simulation_join_pthreads(t_philo *p, t_table *t, pthread_t *paths)
{
	int				i;

	i = -1;
	while (++i < t->total_philo)
	{
		if (pthread_join (paths[i], NULL))
		{
			void_cleaner(paths);
			ft_mutex_destroy (p, t);
			clean_exit(p, t, 1);
		}
	}
	ft_mutex_destroy(p, t);
	void_cleaner(paths);
}

void	simulation_monitor(t_philo *philo, t_table *table)
{
	long long		last_timestamp;
	int				i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->mtx_meals);
		last_timestamp = philo[i].last_meal;
		pthread_mutex_unlock(& table->mtx_meals);
		if (check_if_all_ate_enough(philo, table))
		{
			set_flag_of_close(table);
			philo_print_task(philo, "everyone ate enough");
			break ;
		}
		if (ft_current_ms () - last_timestamp >= table->time_to_die)
		{
			set_flag_of_death(table);
			philo_print_task(& philo[i], "died");
			break ;
		}
		i = (i + 1) % table->total_philo;
		usleep (100);
	}
}
