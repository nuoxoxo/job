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

#ifndef SIMPLE_SHELL_H
# define SIMPLE_SHELL_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "string.h"
# include "sys/wait.h"
# include "sys/types.h"

# define history_ioor	printf("no such command (index out of range) \n")
# define history_invi	printf("no such command (invalid index) \n")
# define history_empty	printf("no commands in history \n")
# define invalid_cmd	printf("invalid command. \n")
# define stdin_error	printf("stdin error. \n")
# define fork_error	printf("fork error. \n")
# define endl2		printf("\n\n")
# define endl		printf("\n")
//# define prompt		printf( _gn "moka $ " _rs )
# define prompt		printf( _gn "(°  ʖ °) $ " _rs )
# define Max_args	64
# define Max_pair	12

char	  		*history[Max_pair][Max_args / 2 + 1];
char 			**history_computation(char **,int *);
void			init_history(void);
void			free_history(void);
void			show_history(void);
void			show_argv(int, char **);

# define _gn		"\x1b[32m"
# define _cn		"\x1b[36m"
# define _rs		"\x1b[0m"
# define _yw		"\x1b[33m"
# define _br		"\x1b[33;1m"

#endif
