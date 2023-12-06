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

/* 	step 1 :: check & allocate

		- check_params
		- table -> malloc
		- philo -> malloc

	step 2 :: parse

		- parse table
		- parse philo

	step 3 :: simulate

		- init paths, load routine
		- join paths
		- cleanup
			- free structs & mutexes
*/

int	main(const int c, const char **v)
{
	pthread_t		*paths;
	t_table			*table;
	t_philo			*philo;

	check_params(c, v);
	table = malloc(sizeof(t_table));
	if (! table)
		clean_exit(NULL, NULL, 1);
	philo = malloc(sizeof(t_philo) * ft_atoi(v[1]));
	if (! philo)
		clean_exit(NULL, table, 1);
	paths = malloc (sizeof(pthread_t) * ft_atoi(v[1]));
	if (! paths)
		clean_exit(philo, table, 1);
	if (! parse_table(table, c, v))
		clean_exit(philo, table, 1);
	if (! parse_philo(philo, table))
		clean_exit(philo, table, 1);
	simulation_init_all_mutex(philo, table);
	simulation_launch_routine(philo, table, paths);
	simulation_monitor(philo, table);
	simulation_join_pthreads(philo, table, paths);
	clean_exit(philo, table, 0);
	return (0);
}
