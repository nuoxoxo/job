#include "unistd.h"
#include "pthread.h"
#include "stdlib.h" // atoi

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
		l = 1 + atoi(v[1]);
		r = 1 + atoi(v[2]);
	}
	//print_left(NULL);
	pthread_create(& pt, NULL, & print_left, NULL); /* side */
	print_right(); /* main */
}

void	*print_left(void *arg)
{
	int	i;

	i = l;
	while (--i)
	{
		usleep(n);
		write(1, "<<<<<<         \n", 16);
	}
	(void) arg;
	return (NULL);
}

void	print_right(void)
{
	int	i;

	i = r;
	while (--i)
	{
		usleep(n);
		write(1, "         >>>>>>\n", 16);
	}
}
