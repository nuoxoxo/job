#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"
#include "stdlib.h" // calloc
#define nl "\n"
#define nl2 "\n\n"
#define c0 "\033[33m"
#define c1 "\033[36m"
#define c2 "\033[32m"
#define c3 "\033[35m"
#define noc "\033[0m"
#define print printf
#define null NULL

/*
 *
 *	wait() - waits for the 1st child to finish
 *
 */

void	print_parent(int, int);
void	print_child(int, int);

int	main()
{
	int		i = -1, target = 3;
	int		*pids;

	pids = calloc(target, sizeof(int));
	if (! pids)
		return 1;
	while (++i < target)
	{
		pids[i] = fork();

		if (pids[i])
		{
			print_parent(pids[i], i);
			wait(null); // comment out wait to have a scrambled view
		}
		else
		{
			print_child(pids[i], i);
		}
	}
	free(pids);
}

void	print_parent(int pid, int idx)
{
	int	i = -1;

	while (++i < idx)
		print("\t");
	print(c1 "a parent (fork id: %d, index / level: %d)" noc nl, pid, idx + 1);
}

void	print_child(int pid, int idx)
{
	int	i = -1;

	while (++i < idx)
		print("\t");
	print(c0 "\t↳ a child (fork id: %d, index / level: %d)" noc nl, pid, idx + 1);
}
