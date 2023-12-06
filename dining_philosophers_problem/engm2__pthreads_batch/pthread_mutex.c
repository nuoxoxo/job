#include "pthread.h"
#include "stdlib.h"
#include "math.h"
#include "stdio.h"

void	*process_batch(void *arg);

enum
{
	BATCH_SIZE = 100000,
	STEPS = 100000000,
	THREAD_GROUP_SIZE = 12,
};

long long	steps_left = STEPS;
int		total_batches = 0;

int	main()
{
	pthread_t	*group;
	int		i;

	group = malloc(sizeof(pthread_t) * THREAD_GROUP_SIZE);
	if (group == NULL)
		return (EXIT_FAILURE);
	/*	start all threads	*/
	i = -1;
	while (++i < CORES)
		pthread_create(&group[i], NULL, process_batch, NULL);
	/*	wait for every threads to finish	*/
	i = -1;
	while (++i < CORES)
		pthread_join(group[i], NULL);
	printf("total batchess: %d \n", total_batches);
	return (EXIT_SUCCESS);
}

void	*process_batch(void *arg)
{
	long long	start;
	long long	i;
	long long	res;

	while (1)
	{
		if (steps_left < 1)
			return (NULL);
		start = steps_left - BATCH_SIZE;
		steps_left -= BATCH_SIZE;
		++total_batches;
		printf("current process: %lld to %lld \n", start, start + BATCH_SIZE);
		i = start - 1;
		while (++i < start + BATCH_SIZE)
			res = sqrt(i);
	}
	(void) arg;
}
