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

void	print_endl(const char *s)
{
	write(1, s, len(s));
	write(1, "\n", 1);
}

void	print_cout(const char *s)
{
	write(1, s, len(s));
}

void	print_diners(t_philo *philo, int n)
{
	int			i;
	t_philo		*p;

	i = -1;
	while (++i < n)
	{
		p = & philo[i];
		printf(" \npho eater %d: \n", p->id);
		printf("pho(s) eaten : %d \n", p->eaten);
		printf("started eating last meal at %lld \n", p->last_meal);
		// printf("philo %d is located at %lu \n", p->id, p->thread); // ubu
		printf("philo %d is located at %p \n", p->id, p->thread); // osx
		printf("table is located at : %p \n", p->table);
		printf("accessed by pointer : %p \n", p->table);
	}
}

void	print_table(t_table *table)
{
	printf(" \ntotal philo: %d \n", table->total_philo);
	if (table->meals > -1)
		printf("meals to eat: %d \n", table->meals);
	printf("time required to eat: %d \n", table->time_to_eat);
	printf("time required to die: %d \n", table->time_to_die);
	printf("time required to sleep: %d \n", table->time_to_sleep);
	printf("time at ground zero: %d \n", (int) table->t0);
	printf("death: %d \n", table->flag_of_death);
	printf("table is located at : %p \n\n", table); // osx
	// printf("table is located at : %lu \n\n", table); // osx
}

void	print_params(const int c, const char **v)
{
	int		i;

	write(1, "\n", 1);
	i = 0;
	while (++i < c)
	{
		print_endl(v[i]);
	}
	write(1, "\n", 1);
}
