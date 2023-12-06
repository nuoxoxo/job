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

void	print_endl(const char *s)
{
	write(1, s, len(s));
	write(1, "\n", 1);
}

void	print_cout(const char *s)
{
	write(1, s, len(s));
}

void	print_diners(t_table *table)
{
	t_philo		*p;
	int			i;

	i = -1;
	while (++i < table->total_philo)
	{
		p = & table->philo[i];
		print("Pho eater %d: \n", p->id);
		print("Left chopstick's number: %d \n", p->left_chop);
		print("Right chopstick's number: %d \n", p->right_chop);
		print(" ├── time required to eat: %d \n", p->time_to_eat);
		print(" ├── time required to die: %d \n", p->time_to_die);
		print(" └── timme required to sleep: %d\n", p->time_to_sleep);
		print("Last pho observed at: %d \n", p->t_prev_meal);
		print(" ├── %d pho(s) eaten so far \n", p->eaten);
		print(" └── %d more pho(s) to eat\n", table->meals - p->eaten);
		print("Table is located at : %p \n", *p->table);
		print("accessed by pointer : %p \n\n", p->table);
	}
}

void	print_table(t_table *table)
{
	print("total philo: %d \n", table->total_philo);
	if (table->meals)
		print("meals to eat: %d \n", table->meals);
	print("time required to eat: %d \n", table->time_to_eat);
	print("time required to die: %d \n", table->time_to_die);
	print("time required to sleep: %d \n", table->time_to_sleep);
	print("time elapsed: %d \n", (int) table->t_0);
	print("death: %d \n\n", table->death);
}

void	print_params(const int c, const char **v)
{
	int		i;

	write(1, "\n", 1);
	i = 0;
	while (++i < c)
	{
		print_endl(v[i]);
	}
	write(1, "\n", 1);
}

/* use len from printf */

/*
int	len(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && ++i)
		;
	return (i);
}
*/
