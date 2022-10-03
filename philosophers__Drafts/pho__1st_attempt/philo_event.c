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

void	*waiter_routine(void *_table)
{
	t_table		*table;
	t_philo		*philo;
	int			i;

	table = _table;
	philo = table->philo;
	while (1)
	{
		i = -1;
		while (++i < table->total_philo)
		{
			if (table->meals && table->meals == philo[i].eaten)
				return (NULL);
			if (fetch_time(table) - philo[i].t_prev_meal >= philo[i].time_to_die)
			{
				table->death = 1;
				pthread_mutex_lock(& table->writer_block);
				printf("%lld philo %d died \n",\
					fetch_time(table) - philo->t_0, philo->id);
				return (NULL);
			}
		}
	}
	return (NULL);
}

void	*philo_routine(void *philo_i)
{
	t_philo		*philo;
	t_table		*table;

	philo = (t_philo *) philo_i;
	table = philo->table;
	if (philo->id % 2 == 0)
	{
		/* report ...is thinking */
		philo_write(table, philo, "starts thinking \n");
		usleep(50);
	}
	while (table->death == 0)
	{
		if (table->meals && table->meals == philo->eaten)
			return (NULL);
		if (table->death || table->total_philo == 1)
		{
			philo_eat(table, philo);
			return (NULL);
			philo_sleep(table, philo);
			philo_think(table, philo);
		}
	}
	return (NULL);
}

void	philo_eat(t_table *table, t_philo *philo)
{
	if (table->death)
		return ;
	pthread_mutex_lock(& table->chops[philo->left_chop]);
	philo_write(table, philo, "picks up the chopstick on the left \n");
	if (table->total_philo == 1)
	{
		pthread_mutex_unlock(& table->chops[table->philo->left_chop]);
		return ;
	}
	pthread_mutex_lock(& table->chops[philo->right_chop]);
	philo_write(table, philo, "picks up the chopstick on the right \n");
	philo_write(table, philo, "starts eating \n");
	philo->eaten += 1;
	philo->t_prev_meal = fetch_time(table);
	philo_spend_time(philo->time_to_eat, table);
	pthread_mutex_unlock(& table->chops[philo->left_chop]);
	pthread_mutex_unlock(& table->chops[philo->right_chop]);
}

void	philo_think(t_table *table, t_philo *philo)
{
	if (table->death)
		return ;
	philo_write(table, philo, "thinks. \n");
	/* no preset thinking time */
}

void	philo_sleep(t_table *table, t_philo *philo)
{
	if (table->death)
		return ;
	philo_write(table, philo, "sleeps. \n");
	philo_spend_time(philo->time_to_sleep, table);
}

void	philo_write(t_table *table, t_philo *philo, char *msg)
{
	if (table->death)
		return ;
	pthread_mutex_lock(& table->writer_block);
	if (table->death)
		return ;
	printf("%lld %d %s ", fetch_time(table) - philo->t_0, philo->id, msg);
	pthread_mutex_unlock(& table->writer_block);
}

void	philo_spend_time(long long time, t_table *table)
{
	long long	start;

	start = fetch_time(table);
	while (time > fetch_time(table) - start && usleep(100))
		;
}

