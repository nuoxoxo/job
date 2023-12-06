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

// static void		void_cleaner(void *tmp);

void	clean_exit(t_philo *philo, t_table *table, int exit_granted)
{
	int				i;

	if (table)
	{
		// if (table->mtx_death)
			pthread_mutex_destroy(& table->mtx_death);
		// if (table->mtx_print)
			pthread_mutex_destroy(& table->mtx_print);
		// if (table->mtx_meals)
			pthread_mutex_destroy(& table->mtx_meals);
		// if (table->mtx_close)
			pthread_mutex_destroy(& table->mtx_close);
		void_cleaner(table);
	}
	if (philo)
	{
		if (philo->chops)
		{
			i = -1;
			while (++i < table->total_philo)
				pthread_mutex_destroy(& philo->chops[i]);
		void_cleaner(philo);
		}
	}
	if (exit_granted)
		exit (1);
}

/*
	table mtx to free:

	pthread_mutex_t		mtx_death; // set Death flag
	pthread_mutex_t		mtx_print;
	pthread_mutex_t		mtx_meals; // count meals
	pthread_mutex_t		mtx_close; // set Close flag

*/

void	void_cleaner(void *tmp)
{
	if (tmp)
		free(tmp);
	tmp = NULL;
}
