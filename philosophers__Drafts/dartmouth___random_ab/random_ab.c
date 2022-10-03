#include "stdio.h"
#include "stdlib.h"
#include "pthread.h"
#include "unistd.h"

void	*print_i(void *);

int	main()
{
	pthread_t		t;

	pthread_create(& t, NULL, print_i, NULL); // t1
	write(1, "c - main thread\n", 16);
}

void	*print_i(void *ptr)
{
	write(1, "a \n", 3);
	write(1, "b \n", 3);
	(void)	ptr;
	return NULL;
}
