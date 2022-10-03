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

static void	parse_table_1(t_table *t, const int c, const char **v);
static void	parse_table_2(t_table *t, const int c, const char **v);

void	parse_table(t_table *table, const int c, const char **v)
{
	parse_table_1(table, c, v);
	parse_table_2(table, c, v);
}

void	parse_philo(t_philo *philo, int total_philo)
{
	int			i;

	i = -1;
	while (++i < total_philo)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].eaten = 0;
	}
}

//	helpers

static void	parse_table_1(t_table *table, const int c, const char **v)
{
	if (c < 5 || c > 6 || ! table)
		return ;
	table->total_philo = ft_atoi(v[1]);
	table->time_to_die = ft_atoi(v[2]);
	table->time_to_eat = ft_atoi(v[3]);
	table->time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
	{
		table->meals = ft_atoi(v[5]);
		return ;
	}
	table->meals = 0;
}

static void	parse_table_2(t_table *table, const int c, const char **v)
{
	table->chops = malloc(sizeof(pthread_mutex_t) * table->total_philo);
	if (table->chops == NULL)
		clean_exit(NULL, table, 1);
	table->flag_of_death = 0;
	table->t0 = fetch_time();
	(void) c;
	(void) v;
}
