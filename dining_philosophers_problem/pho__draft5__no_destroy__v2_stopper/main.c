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

int	main(const int c, const char **v)
{
	t_table		*table;
	t_philo		*philo;

	check_params(c, v);
	table = malloc(sizeof(t_table));
	if (table == NULL)
		exit (1);
		// clean_exit(NULL, table, 1);
	philo = malloc(sizeof(t_philo) * ft_atoi(v[1]));
	if (!philo)
		exit (1);
		// clean_exit(philo, table, 1);
	parse_table(table, c, v);
	parse_philo(philo, ft_atoi(v[1]));
	table->philo = philo; // new in isFull mod
	simulation_initialize(philo, table);
	simulation_jointhread(philo, table);
	// simulation_destroyall(table); // when do we need to destroy mutexes
	clean_exit(philo, table, 0);
	return (0);
}
