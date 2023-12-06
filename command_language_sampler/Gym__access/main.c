#include "stdio.h"
#include "unistd.h"
#include "errno.h"

//	prototype
//	int access(const char *pathname, int mode);

//	second argument "mode" takes flags:
//		R_OK, W_OK, X_OK or F_OK.

/*

F_OK flag : Used to check for existence of file.
R_OK flag : Used to check for read permission bit.
W_OK flag : Used to check for write permission bit.
X_OK flag : Used to check for execute permission bit.

*/

char	*path = "in.0";

int	main(void)
{
	int	fd;

	fd = access(path, F_OK);
	if (fd == -1)
	{
		printf("errno : %d \n", errno);
		perror("error ");
		return 0;
	}
	printf("if you are here it means that \"%s\" exits \n", path);
	return 0;
}
