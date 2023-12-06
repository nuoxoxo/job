//

#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"

#define Fixed_size	16

char			*g_msg1 = "0123456789abcde";
char			*g_msg2 = "012345678912345";
char			*g_msg3 = "Hello, World!!!"; // need 15 not 16

int	main()
{
	char		buff_in[Fixed_size];
	int			pipe_fd[2];
	int			i;

	if (pipe(pipe_fd) < 0)
		exit (1);
	write(pipe_fd[1], g_msg1, Fixed_size);
	write(pipe_fd[1], g_msg2, Fixed_size);
	write(pipe_fd[1], g_msg3, Fixed_size);
	for (i = 0; i < 3; i++)
	{
		read(pipe_fd[0], buff_in, Fixed_size);
		printf("%s \n", buff_in);
	}
}
