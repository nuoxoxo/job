//

#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#define nl "\n"
#define yel "\033[33m"
#define cyn "\033[36m"
#define noc "\033[0m"


int	main()
{
	int	fd[2];

	// 0 : read end
	// 1 : write end

	if (pipe(fd) == -1)
	{
		printf("error (pipe)" nl);
		return 1;
	}

	int	pid = fork();

	if (pid == 0) // child
	{
		int	x;

		close(fd[0]);

		// we dont read, so close it
		// standard op for pipe: close the unused end in each process

		printf(cyn "input: " noc);
		scanf("%d", &x);
		// write(fd[1], &x, sizeof(int)); // alt: put write/read in if
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("error (write)" nl);
			return 2;
		}
		close(fd[1]);
	}
	else // parent
	{
		int	received;

		close(fd[1]);
		// read(fd[0], & received, sizeof(int)); // alt: put in if
		if (read(fd[0], & received, sizeof(int)) == -1)
		{
			printf("error (read)" nl);
			return 1;
		}
		close(fd[0]);
		printf(yel "from child with love: " noc);
		printf("%d" nl, received);
	}
}
