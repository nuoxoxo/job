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

#include "./../philo.h"

void	setup_time(t_table *table)
{
	int		i;

	if (! table)
		return ;
	i = -1;
	table->t_0 = fetch_time(table);
	while (++i < table->total_philo)
	{
		table->philo[i].t_0 = table->t_0;
		table->philo[i].t_prev_meal = table->t_0;
	}
}

/*
 *
 * 	1 millisecond = 10^(-3) s
 *
 * 	1 microsecond = 10^(-6) s
 *
 */

//long long	fetch_time(t_table *table)
long long	fetch_time(t_table *table)
{
	struct timeval		tv;
	long long		second_to_millis;
	long long		micros_to_millis;

	if (gettimeofday(& tv, NULL))
	{
		__exit_safe__(table);
	}
	micros_to_millis = tv.tv_usec / 1000;
	second_to_millis = tv.tv_sec * 1000;
	return (micros_to_millis + second_to_millis);
}
