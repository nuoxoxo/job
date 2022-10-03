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

		- init threads, load routine
		- join threads
		- cleanup
			- free structs & mutexes
*/

int	main(const int c, const char **v)
{
	pthread_t		*threads;
	t_table			*table;
	t_philo			*philo;

	/* step 1 :: check params */

	check_params(c, v);

	/* step 2 :: allocate */

	table = malloc(sizeof(t_table));
	if (! table)
		clean_exit(NULL, NULL, 1);
	philo = malloc(sizeof(t_philo) * ft_atoi(v[1]));
	if (! philo)
		clean_exit(NULL, table, 1);
	threads = malloc (sizeof(pthread_t) * ft_atoi(v[1]));
	if (! threads)
		clean_exit(philo, table, 1);

	/* step 3 :: parse table & philo_group */

	if (! parse_table(table, c, v))
		clean_exit(philo, table, 1);

	if (! parse_philo(philo, table))
		clean_exit(philo, table, 1);


	/* step 4 :: the sims */

	simulation_init_all_mutex(philo, table);
	simulation_launch_routine(philo, table, threads); // New in v7
	ft_arbitrator(philo, table);
	simulation_join_pthreads(philo, table, threads);
	clean_exit(philo, table, 0);
	return (0);
}
