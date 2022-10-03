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

// void	*philo_routine(void *philo)
// {
// 	t_philo			*p;

// 	p = (t_philo *) philo;
// 	while (! end_is_nigh(p))
// 	{
// 		philo_eat(p);
// 		philo_sleep_and_think(p);
// 	}
// 	return (NULL);
// }

/*		Above part :: deprecated		*/

void	*philo_routine(void *p)
{
	t_philo			*philo;

	philo = (t_philo *) p;
	if (philo->id % 2 == 0) // delay even philo
	{
		philo_print_task(philo, "is thinking");
		philo_pass_time(philo, philo->table->time_to_eat);
	}
	while (1)
	{
		if (someone_is_dead(philo))
			break ;
		if (everyone_ate_enough(philo))
			break ;
		if (! philo_eat(philo))
			break ;
		philo_print_task(philo, "is sleeping");
		philo_pass_time(philo, philo->table->time_to_sleep);
		philo_print_task(philo, "is thinking");
		if (philo->table->time_to_eat > philo->table->time_to_sleep)
			philo_pass_time(philo, (philo->table->time_to_eat - philo->table->time_to_sleep) + 1);
		else // above line: why +1
			philo_pass_time(philo, 1); // why 1
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

void	simulation_launch_routine(t_philo *philo, t_table *table, pthread_t * threads)
{
	int				i;

	i = -1;
	while (++i < table->total_philo)
	{
		if (pthread_create(& threads[i], NULL, philo_routine, & philo[i]))
		{
			while (i--)
				pthread_join(threads[i], NULL);
			free(threads);
			clean_exit(philo, table, 1);
		}
	}
	// ft_arbitrator (philo, table);
}

void	simulation_join_pthreads(t_philo *philo, t_table *table, pthread_t * threads)
{
	int				i;

	i = -1;
	// ft_arbitrator (philo, table);
	while (++i < table->total_philo)
	{
		if (pthread_join (threads[i], NULL))
		{
			void_cleaner(threads);
			ft_mutex_destroy (philo, table);
			clean_exit(philo, table, 1);
		}
	}
	ft_mutex_destroy(philo, table);
	void_cleaner(threads);
}

void	ft_mutex_destroy(t_philo *philo, t_table *table)
{
	int			i;

	i = -1;
	while (++i < table->total_philo)
		pthread_mutex_destroy(& philo->chops[i]); // crucial fix
	pthread_mutex_destroy(& table->mtx_death);
	pthread_mutex_destroy(& table->mtx_print);
	pthread_mutex_destroy(& table->mtx_meals);
	pthread_mutex_destroy(& table->mtx_close);
}

void ft_arbitrator(t_philo *philo, t_table *table)
{
	long long		last_timestamp;
	int				diff;
	int				i;

	i = 0;
	while (1)
	{
		pthread_mutex_lock(&table->mtx_meals);
		last_timestamp = philo[i].last_meal;
		pthread_mutex_unlock(&table->mtx_meals);
		// if (last_timestamp && check_if_all_ate_enough(philo, table))
		if (check_if_all_ate_enough(philo, table))
		{
			set_flag_of_close(table);
			philo_print_task(philo, "everyone ate enough");
			break ;
		}
		diff = ft_current_ms () - last_timestamp;
		if (diff >= table->time_to_die)
		{
			set_flag_of_death(table);
			philo_print_task(& philo[i], "died");
			break ;
		}
		i = (i + 1) % table->total_philo;
		usleep (100);
	}
}

int	ft_minmax(int x, int y, int op)
{
	if (op)
	{
		if (x > y)
			return (x);
		return (y);
	}
	if (x > y)
	{
		return (y);
	}
	return (x);
}