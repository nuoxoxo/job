#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"
#define nl "\n"
#define nl2 "\n\n"
#define c0 "\033[0;37m"
#define c1 "\033[33m"
#define c2 "\033[36m"
#define c3 "\033[32m"
#define c4 "\033[35m"
#define noc "\033[0m"
#define null NULL
#define print printf

void	print_result_and_forkid(int r, int f);

int	main()
{
	int	arr[] = {1, 2, 3, 4, 1, 2};
	int	size = sizeof(arr) / sizeof(int);
	int	start;
	int	end;
	int	res;
	int	i;
	int	fork_id;
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1) { return 1; } // pipe: err mgmt
	if ((fork_id = fork()) == -1) { return 2; } // fork: err mgmt

	if (fork_id) // parent handles range: [size / 2] ➜ [size]
	{
		start = size / 2;
		end = size;
	}
	else // child handles range: [0] ➜ [size / 2]
	{
		start = 0;
		end = size / 2;
	}
	res = 0;
	i = start - 1; // each proc has diff start: parent has len/2, child has 0
	while (++i < end)
	{
		res += arr[i];
	}
	print_result_and_forkid(res, fork_id);
}

void	print_result_and_forkid(int r, int f)
{
	print(c2 "sum = %d " noc, r);
	print(c0 "result came from proc[%d]" nl noc, f);
	
}
