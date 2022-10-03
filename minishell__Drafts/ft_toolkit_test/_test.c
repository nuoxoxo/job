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

#include "_test.h"

int	g_exit_status = ON_SUCCESS;

int	main(int c, char **v, char **env)
{
	if (c ^ 1)
		return (1);
	/* pre-shell setup -- env . signal */


	/* ending pre-shell */
	/* main loop */

	print("print output: hello world!\n");
	print("putnb_fd output: ");
	ft_putnbr_fd(42, 0);
	while ((int) 1e9)
		;

	/* ending main loop */
	(void) v;
	(void) env;
	return (g_exit_status);
}
