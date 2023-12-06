/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include "errno.h"

void	handle_err(int);

int     main(int c, char **argv, char **env)
{
	char	*envp[] = { NULL };

	argv += 1;
	if (! strcmp("/bin/ls", *argv)
	&& execve("/bin/ls", argv, envp) == -1)
	{
		handle_err(errno);
	}
	else if (! strcmp("/bin/cat", *argv)
	&& execve("/bin/cat", argv, envp) == -1)
	{
		handle_err(errno);
	}
	else if (! strcmp("/bin/pwd", *argv)
	&& execve("/bin/pwd", argv, envp) == -1)
	{
		handle_err(errno);
	}
	else if (! strcmp("/usr/bin/whereis", *argv)
	&& execve("/usr/bin/whereis", argv, envp) == -1)
	{
		handle_err(errno);
	}
	else if (! strcmp("/usr/bin/whoami", *argv)
	&& execve("/usr/bin/whoami", argv, envp) == -1)
	{
		handle_err(errno);
	}
	else if (! strcmp("/usr/bin/env", *argv)
	&& execve("/usr/bin/env", argv, env) == -1) // notice env here
	{
		handle_err(errno);
	}
	(void) c;
	return 0;
}

void	handle_err(int e)
{
	fprintf(stderr, "Error: %s \n", strerror(e));
}
