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
#define null NULL
#define p printf

/*
 *
 *	wait() - waits for the 1st child to finish
 *
 */

int	main()
{
	int	fid = fork();
	int	ffid = fork();

	if (fid)
	{
		p(c1 "parent (fork id: %d)" noc nl, fid);
		wait(null); // comment out wait to have a scrambled view
	}
	else
	{
		if (ffid)
		{
			p(c0 "\t↳ child as parent (fork id: %d)" noc nl, fid);
			wait(null);
		}
		else
		{
			p(c3 "\t\t↳ child's own child (fork id: %d)" noc nl, ffid);
		}
	}
}
