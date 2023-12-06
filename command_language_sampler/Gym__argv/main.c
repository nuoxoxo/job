#include "stdio.h"

int	main(int c, char **v)
{
	int		i;

	i = 0;
	while (v[++i])
	{
		printf("String %.2d: %s \n", i, v[i]);
	}
	(void) c;
}
