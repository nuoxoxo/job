#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

int	main(int c, char **v)
{
	if (c ^ 2)
		return 1;
	exit(atoi(v[1]));
}
