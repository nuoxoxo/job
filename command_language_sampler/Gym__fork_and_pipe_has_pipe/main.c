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
int	arr[] = {1, 2, 3, 4, 1, 2};

//	original example: 
// int	arr[] = {1, 2, 3, 4, 1, 2};

int	main()
{
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
	if (!fork_id) // child . creme de la creme
	{
		close(pipe_fd[0]); // read nothing under child
		write(pipe_fd[1], & res, sizeof(res)); // write the write end
		close(pipe_fd[1]); // close fd when done writing or reading
	}
	else // parent
	{
		int		res_from_child;

		close(pipe_fd[1]); // 1. close the end we don't use
		read(pipe_fd[0], & res_from_child, sizeof(int)); // 2. using pipe
		close(pipe_fd[0]); // 3. close after using
		res += res_from_child; // 4. parent uses the data received via pipe
		print_result_and_forkid(res, fork_id); // 4. (cont.)
		wait(NULL); // 5. wait for first child to finish
	}
}

void	print_result_and_forkid(int r, int f)
{
	print(c1 "sum = %d " noc nl, r);
	print(c3 "result came from proc[%d]" nl noc, f);
	print(c0 "(try adding elements to the array)" nl noc);
	
}
