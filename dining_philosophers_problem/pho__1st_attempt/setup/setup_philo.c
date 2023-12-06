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
/* ****************************************************************** nxu *** */

#include "./../philo.h"

static void	setup_collective(t_table *table);
static void	setup_individual(t_table *table);

void	setup_philo(t_table *table)
{
	setup_collective(table);
	setup_individual(table);
}

//	helpers

static	void	setup_collective(t_table *table)
{
	int		i;

	i = table->total_philo;
	table->philo = malloc(i * sizeof(t_philo));
	if (!table->chops)
		__exit_safe__(table);
	table->thread = malloc(i * sizeof(pthread_t)); // 1 thread per person
	if (!table->thread)
		__exit_safe__(table);
	if (!table->philo)
		__exit_safe__(table);
	table->chops = malloc(i * sizeof(pthread_mutex_t)); // 1 mtx per chop
	i = -1;
	while (++i < table->total_philo) // mutexes should be init
	{
		if (pthread_mutex_init(& table->chops[i], NULL))
		{
			__exit_safe__(table);
			return ;
		}
	}
}

static void	setup_individual(t_table *table)
{
	int		i;

	i = -1;
	while (++i < table->total_philo)
	{
		table->philo[i].left_chop = i;
		table->philo[i].right_chop = i + 1;
		if (i == table->total_philo - 1)
			table->philo[i].right_chop = 0;
		table->philo[i].time_to_eat = table->time_to_eat;
		table->philo[i].time_to_die = table->time_to_die;
		table->philo[i].time_to_sleep = table->time_to_sleep;
		table->philo[i].t_prev_meal = table->t_0;
		table->philo[i].t_0 = table->t_0;
		table->philo[i].eaten = 0;
		table->philo[i].id = i + 1;
		table->philo[i].table = table;
	}
}
