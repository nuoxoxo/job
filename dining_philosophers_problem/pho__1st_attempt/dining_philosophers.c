/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

#include "philo.h"

static void	begin_routine(
			t_table		*table, 
			void		*philo_routine, 
			pthread_t 	waiter, 
			void		*waiter_routine
		);

static void	unite_threads(
			t_table		*table,
			pthread_t	waiter
		);

void	dining_philosophers(t_table *table)
{
	pthread_t	waiter;

	waiter = NULL;
	setup_time(table);
	begin_routine(
			table, 
			& philo_routine, 
			waiter, 
			& waiter_routine
		);
	unite_threads(table, waiter);
}

static void	begin_routine(
		t_table *table, 
		void *philo_routine, 
		pthread_t waiter, 
		void *waiter_routine)
{
	int		i;

	i = -1;
	while (++i < table->total_philo)
	{
		pthread_create(
				& table->thread[i], 
				NULL, 
				philo_routine,
				& table->philo[i]
			);	/* setup everyone's own routine */
	}
	pthread_create(
			& waiter, 
			NULL, 
			waiter_routine, 
			table
		);	/* setup waiter's routine */
}

static void	unite_threads(t_table *table, pthread_t waiter)
{
	int		i;

	pthread_mutex_unlock(& table->writer_block);
	pthread_join(waiter, NULL);
	i = -1;
	while (++i < table->total_philo)
	{
		pthread_join(table->thread[i], NULL);
	}
}
