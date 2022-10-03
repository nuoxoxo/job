#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "unistd.h"

char	s1[] = "abcdefg";
char	s2[] = "abc";
char	*c;

void	print_last_letter(char *a);
void	*func(void *ptr);
int	len(char *s);

int	main()
{
	pthread_t	t;

	pthread_create(& t, NULL, func, NULL);
	print_last_letter(s1);
	sleep(1);
	printf("Program exited successfully. \n");

	exit (0); //never reached when c = NULL uncommented
}

//

void	print_last_letter(char *a)
{
	int		i;

	i = len(a);
	printf("len is %d, last letter in %s is: \n", i, a);
	sleep(i);

	//c = NULL;

	//sleep(i % 3);
	c = a;
	//sleep(i % 3);
	while (*(c) && ++c)
		;
	printf("%c \n", *(c - 1));
}

void	*func(void *ptr)
{
	print_last_letter(s2);
	return ptr;
}

int	len(char *s)
{
	int		tt;

	tt = 0;
	if (! s)
		return tt ;
	while(s[tt] && ++tt)
		;
	return tt;
}
