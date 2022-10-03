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

static void	setup_1(const int ___, const char **_, t_table *__);
static void	setup_2(const int ___, const char **__, t_table *_);

void	setup_table(const int c, const char **v, t_table *table)
{
	setup_1(c, v, table);
	setup_2(c, v, table);
}

//	helpers

static void	setup_1(const int c, const char **v, t_table *table)
{
	if (c < 5 || c > 6 || ! table)
		return ;
	table->total_philo = ft_atoi(v[1]);
	table->time_to_die = ft_atoi(v[2]);
	table->time_to_eat = ft_atoi(v[3]);
	table->time_to_sleep = ft_atoi(v[4]);
	if (c == 6)
	{
		table->meals = ft_atoi(v[5]);
		return ;
	}
	table->meals = -1;
}

static void	setup_2(const int c, const char **v, t_table *table)
{
	table->thread = NULL;
	table->philo = NULL;
	table->chops = NULL;
	table->death = 0;
	table->t_0 = 0;
	(void) c;
	(void) v;
}
