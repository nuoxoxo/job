#include "philo.h"

void	__exit__(char *s)
{
	if (s == NULL)
		perror("usage: ./philo {arg 1: how_many_persons} {arg2: time_required_for_eat_or_sleep} \n");
	perror(s);
	exit(1);
}
