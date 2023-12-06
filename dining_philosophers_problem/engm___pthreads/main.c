#include "stdio.h"
#include "pthread.h"
#include "stdlib.h"
#define ll long long

enum
{
	TARGET = 100000,
	SIZE = 29,
};

void		*counting(void *arg);
ll		n = 0;

int	main()
{
	pthread_t	*group;
	int		i;

	group = malloc(sizeof(pthread_t) * SIZE);
	if (group == NULL)
		return (EXIT_FAILURE);

	/*	start all threads by pthread_create	*/

	i = -1;
	while (++i < SIZE)
	{
		pthread_create(& group[i], NULL, counting, NULL);
	}

	/*	wait until every threads to finish	*/

	i = -1;
	while (++i < SIZE)
	{
		pthread_join(group[i], NULL);
	}

	return (EXIT_SUCCESS);
}

void	*counting(void *arg)
{
	for (;;)
	{
		if (n >= TARGET)
		{
			break ;
		}
		n += 1;
		printf("n = %lld \n", n);
	}
	(void) arg;
	return (NULL);
}
