#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"

# define MSG_1 "This will be output to the file named in.0 \n"
# define MSG_2 "This will be output to the file named in.0 too \n"

# define LEN_1 44
# define LEN_2 48

int	main()
{
	int	fd_src;
	int	fd_copy;

	fd_src = open("in.0", O_WRONLY | O_CREAT, 0777);

	if (fd_src < 0)
		printf("Error opening the file\n");

	//	notes:
	//		dup() creates a copy of file descriptor: fd_copy
	//		then now both file descriptors can be used interchangeably.

	// fd_copy = open("in.0", O_WRONLY | O_CREAT, 0777); // not the same, uncom to see errors
	fd_copy = dup(fd_src);

	write(fd_copy, MSG_1, LEN_1);
	write(fd_src, MSG_2, LEN_2);
}
