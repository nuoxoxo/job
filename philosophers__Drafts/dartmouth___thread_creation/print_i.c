#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h" // sleep . usleep

void	*print_i(void *);

int	i;

int	main()
{
	pthread_t		t;

	i = 0;
	pthread_create(& t, NULL, print_i, NULL);
	while (i < (8 << 2) + 1)
	{
		usleep(90000);
		i ++;
		printf("%d \n", i - 1);
	}
	exit (0); /* never reached */
}

void	*print_i(void *ptr)
{
	while (1)
	{
		usleep(90000);
		printf("%d \n", i);
	}
	(void) ptr;
}
