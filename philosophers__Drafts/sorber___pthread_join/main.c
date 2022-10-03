#include "unistd.h"
#include "stdio.h"
#include "stdlib.h" // atoi
#include "pthread.h"

void	*print_left(void *);
void	print_right(void);
int	n = 1e5;
int	l = 8;
int	r = 16;

int	main(int c, char **v)
{
	pthread_t	pt;

	if (c == 3)
	{
		l = atoi(v[1]);
		r = atoi(v[2]);
	}
	pthread_create(& pt, NULL, & print_left, NULL);
	print_right();
	pthread_join(pt, NULL); // IBM says "join() - Wait for a thread to end"
}

//

void	*print_left(void *arg)
{
	int	i = -1;

	while (++i < l)
	{
		usleep(n);
		printf("%02d <<<<<<         \n", i);
	}
	(void) arg;
	return (NULL);
}

void	print_right(void)
{
	int	i = -1;

	while (++i < r)
	{
		usleep(n);
		printf("%02d         >>>>>>\n", i);
	}
}
