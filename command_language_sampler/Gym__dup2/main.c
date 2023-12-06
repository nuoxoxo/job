#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
  
# define MSG_1 "This will be output to the file named in.0 \n"
# define MSG_2 "This will be output to the file named in.0 too \n"

# define LEN_1 44
# define LEN_2 48

int	main()
{
	int	fd;

	fd = open("in.0", O_WRONLY | O_CREAT, 0777);

	if (fd < 0)
		printf("Error opening the file\n");

	dup2(fd, STDOUT_FILENO);

	/*
	 * writing MSG 1
	 *
	 * msg 1 won't be shown in stdout, but will be 
	 * written to the file descriptor because it has been dup2-ed
	 *
	 */

	write(STDOUT_FILENO, MSG_1, LEN_1);

	/*
	 * writing MSG 2
	 *
	 * idem, msg 2 will be written to the FD twice, as the
	 * stdout has the same outlet as the FD now
	 *
	 */

	write(fd, MSG_2, LEN_2);
	write(STDOUT_FILENO, MSG_2, LEN_2);
}
