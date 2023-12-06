#include "stdio.h"

int	main(int c, char **v)
{
	int	i = 0;

	//while (v[i] && v[i + 1])
	while (v[i])
	{
		printf("%d - %s \n", i, *v);
		//v = & v[i + 1];
		v = & v[i + 1];
		printf("%d - %s \n\n", i, *v);
		i++;
	}
	(void) c;
}
