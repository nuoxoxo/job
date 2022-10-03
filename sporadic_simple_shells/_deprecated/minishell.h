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

#ifndef MINISHELL_H
# define MINISHELL_H

# define ON_SUCCESS 0

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <signal.h>

# include "utils_basic.h" // libft

typedef struct	s_redir
{
	struct s_redir	*prev;
	struct s_redir	*next;
	char		*file;
	int		type;
}		t_redir;

typedef struct	s_token
{
	struct s_token	*prev;
	struct s_token	*next;
	char		*cont;
	int		type;
}		t_token;

typedef struct	s_cmd
{
	struct s_cmd	*prev;
	struct s_cmd	*next;
	t_redir		*redir;
	char		**exec;
	char		*arg;
	char		*cmd;
}		t_cmd;

typedef struct	s_command_line
{
	struct	s_command_line	*prev;
	struct	s_command_line	*next;
	char			*input;
	t_token			*token;
	t_cmd			*cmd;
}		t_command_line;

typedef struct	s_env_pointer
{
	struct	s_env_pointer	*next;
	char			*cont;
}		t_env_pointer;

// ----------------8<-------[ cut here ]------------------ 

extern int	g_exit_status;

void		start_shell(char **);

void		catch_signal(void);
void		handle_sigint(int);

void		usage(void);
void		exit_prompt(int fd, char *msg, int ret);
void		exit_safe(int exit_code);
void		clean_all(void);

#endif
