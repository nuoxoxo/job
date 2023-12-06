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

#include "unistd.h"
#include "stdlib.h" /* atoi */
#include "stdio.h"

int	len(const char *s);

int	main(int argc, char **argv)
{
	char	*msg;
	int	bytes;

	if (argc == 1)
	{
		msg =  "Hello, World! \n";
		bytes = len(msg);
		write(STDERR_FILENO, msg, bytes); /* the byte length */
	}
	else if (argc == 3 && atoi(argv[2]) < 3)
	{
		write( atoi(argv[2]), argv[1], len(argv[1])  );
	}
	return 0;
}

int	len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && ++i)
		;
	return (i);
}
