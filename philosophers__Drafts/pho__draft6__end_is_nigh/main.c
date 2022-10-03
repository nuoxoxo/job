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

/*	fixed : 
	exit (1) on irregular error
		the modern malloc() will only return NULL as an absolute last resort,
		so if it return NULL we should abort.
	*/

int	main(const int c, const char **v)
{
	t_table		*table;
	t_philo		*philo;

	/* step 1 :: check & allocate . done */

	check_params(c, v);
	table = malloc(sizeof(t_table));
	if (table == NULL)
		exit (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(v[1]));
	if (philo == NULL)
		exit (1);

	/* step 2 :: parse table & philo_group */

	parse_table(table, c, v); // Current
	parse_philo(philo, ft_atoi(v[1]));

	/* step 3 :: the sims */

	simulation_initialize(philo, table);
	simulation_jointhread(philo, table);
	clean_exit(philo, table, 0);
	return (0);
}
