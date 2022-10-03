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

#include "philo.h"

long long	fetch_time(t_table *table);
void		setup_time(t_table *table);

int	main(const int c, const char **v)
{
	t_table		*table;

	check_params(c, v);
	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (1);
	setup_table(c, v, table);
	setup_philo(table);
	dining_philosophers(table);

	__exit_safe__(table);
	// and kill_all_mutexex
	return (0);
}
