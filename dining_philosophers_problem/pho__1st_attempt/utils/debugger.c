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

int	main(const int c, const char **v)
{
	t_table		*table;

	check_params(c, v);
	print_params(c, v);
	table = malloc(sizeof(t_table));
	if (table == NULL)
		return (1);
	setup_table(c, v, table);
	print_table(table);
	setup_philo(table);
	print_diners(table);
}
