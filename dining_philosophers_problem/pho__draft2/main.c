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
		clean_exit(NULL, table, 1);

	philo = malloc(sizeof(t_philo) * ft_atoi(v[1]));
	if (!philo)
		clean_exit(philo, table, 1);

	/* parse */
	parse_table(table, c, v);
	parse_philo(philo, ft_atoi(v[1]));

	/* pre-sim setup */
	simulation_initialize(philo, table);
	print_table(table);
	print_diners(philo, ft_atoi(v[1]));

	/* free, exit not allowed */
	clean_exit(philo, table, 0);
	return (0);
}

/*

//	table: every philo is a thread

typedef struct
{
	struct s_table	*table;
	pthread_t		thread;
	long long		last_meal;
	int				id;
	int				eaten;
}

*//*

//	philo: every chopstick is a mutex

typedef struct
{
	pthread_mutex_t	*chops;
	pthread_mutex_t	mutex;
	long long		t0;
	int				total_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				flag_of_death;
	int				meals;
}

*/
