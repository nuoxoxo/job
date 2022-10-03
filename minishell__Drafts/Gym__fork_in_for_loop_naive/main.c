#include "stdio.h"
#include "unistd.h"
#include "sys/wait.h"
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


int	main()
{
	int		i = -1, target = 2;

	while (++i < target)
	{
		int		fpid = fork();

		if (fpid)
		{
			print(c1 "a parent (fork id: %d, index: %d)" noc nl, fpid, i + 1);
			wait(null); // comment out wait to have a scrambled view
		}
		else
		{
			print(c0 "\t↳ a child (fork id: %d, index: %d)" noc nl, fpid, i + 1);
		}
	}
}
