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
/* ****************************************************************** nxu *** */

#include "./../philo.h"

void	__exit_safe__(t_table *table)
{
	//int		i;

	if (table->philo)
		free(table->philo);
	if (table->chops)
		free(table->chops);
	if (table->thread)
		free(table->thread);
	/*
	i = -1;
	while (++i < table->total_philo)
		if (& table->chops[i])
			pthread_mutex_destroy(& table->chops[i]);
	pthread_mutex_destroy(& table->writer_block);
	*/
	if (table)
		free(table);
	exit (0);
}

void	usage_exit(void)
{
	print_cout("\nUsage: ./philo n1 n2 n3 n4 [n5] \n\n");
	print_cout("n1: number of philosophers \n");
	print_cout("n2: time to die (in ms)\n");
	print_cout("n3: time to eat (in ms)\n");
	print_cout("n4: time to sleep (in ms)\n");
	print_cout("n5: (optional) number of meals each one must eat \n");
	print_cout("\n(number of args required: 5 or 6) \n\n");
	exit (0);
}
