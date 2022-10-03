#include "iostream"
#include "unistd.h"
#include "signal.h"

void	msg(int sig)
{
	//cout << "\nHint: 16 32 64\n16, 32 or 64: "; // cout stops before 2nd \n
	write(1, "\n\nHint: 16 32 64\n16, 32 or 64: ", 31);
}

int	main()
{
	int	pid;

	if ((pid = fork()) < 0)	return 1 ;
	if (pid ^ 0) // parent process
	{
		std::cout << "16, 32 or 64: ";

		struct	sigaction sa ;
		sa.sa_flags = SA_RESTART ;
		sa.sa_handler = &msg ;

		sigaction(SIGUSR1, &sa, NULL);

		int	x;

		scanf("%d", &x);
		if (x == 16 || x == 32 || x == 64)
			std::cout << "Right! \n";
		else
			std::cout << "Wrong! \n";
	}
	else	// child process
	{
		sleep(4) ;
		kill(getppid(), SIGUSR1);
	}

}
