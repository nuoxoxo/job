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
/* ****************************************************************** .go *** */

/*

#define _POSIX_SOURCE
#include <termios.h>

int	tcgetattr(int fd, struct termios *termptr);

*/

#include "termios.h"
#include "unistd.h"
#include "stdio.h"

int	main()
{
	struct termios	term; // term_ptr

	if (! tcgetattr(STDIN_FILENO, & term))
	{
		if (term.c_iflag & BRKINT)
			puts("BRKINT is set");
		else
			puts("BRKINT is not set");
		if (term.c_cflag & PARODD)
			puts("Odd parity is used");
		else
			puts("Even parity is used");
		if (term.c_lflag & ECHO)
			puts("ECHO is set");
		else
			puts("ECHO is not set");
		printf("The end-of-file character is x'%02x'\n",
		term.c_cc[VEOF]);
	}
	else
	{
		perror("tcgetatt() error");
	}
}
