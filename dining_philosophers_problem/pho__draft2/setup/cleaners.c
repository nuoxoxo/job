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

void	void_cleaner(void *tmp);

void	clean_exit(t_philo *philo, t_table *table, int exit_granted)
{
	if (table)
	{
		if (table->chops)
			void_cleaner(table->chops);
	}
	if (philo)
	{
		if (philo->table)
			void_cleaner(philo->table);
		void_cleaner(philo);
	}
	if (exit_granted)
		exit (1);
}

void	void_cleaner(void *tmp)
{
	if (tmp)
		free(tmp);
	tmp = NULL;
}
