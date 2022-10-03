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
	int	fid = fork();
	int	ffid = fork();

	if (fid)
	{
		print(c1 "parent (fork id: %d)" noc nl, fid);
		wait(null); // comment out wait to have a scrambled view
	}
	else
	{
		print(c0 "\t↳ child (fork id: %d)" noc nl, fid);
	}
	if (ffid)
	{
		print(c2 "\t↳ child as a parent (fork id: %d)" noc nl, ffid);
		wait(null);
	}
	else
	{
		print(c3 "\t\t↳ child's own child (fork id: %d)" noc nl, ffid);
	}
}
