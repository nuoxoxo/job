#include "pthread.h"
#include "stdlib.h"
#include "stdio.h"
#define ll long long

enum
{
	TARGET = 100000,
	SIZE = 29,
};

void				*counting(void *arg);
ll				n = 0;
static pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER; // added

int	main()
{
	pthread_t	*group;
	int		i;

	group = malloc(sizeof(pthread_t) * SIZE);
	if (group == NULL)
		return (EXIT_FAILURE);

	/*	start all threads	*/

	i = -1;
	while (++i < SIZE)
		pthread_create(& group[i], NULL, counting, NULL);

	/*	wait for every threads to finish	*/

	i = -1;
	while (++i < SIZE)
		pthread_join(group[i], NULL);
	return (EXIT_SUCCESS);
}

void	*counting(void *arg)
{
	for (;;)
	{
		pthread_mutex_lock(& mutex); /* acquire lock */
		if (n >= TARGET)
		{
			pthread_mutex_unlock(& mutex);
			return (NULL);
			//break ;
		}
		++n;
		pthread_mutex_unlock(& mutex);	/* release lock */
		printf("n = %lld \n", n);
	}
	(void) arg;
	return (NULL);
}
