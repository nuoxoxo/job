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

#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdio.h"
#include "readline/readline.h"
#include "readline/history.h"
#include "sys/types.h"
#include "sys/wait.h"

#define maxcommands 1000
#define maxlistsize 100

#define _yellow	"\x1b[33m"
#define _red	"\x1b[31m"
#define _green	"\x1b[32m"
#define _blue	"\x1b[34m"
#define _mag	"\x1b[35m"
#define _cyan	"\x1b[36m"
#define _reset	"\x1b[0m"

/*	debugger	*/
void	print_string_pair(char **v);
/*	utils	*/
int	check_and_store_pipe(char *, char *ss[2]);
int	get_type(char *, char **, char **);
int	get_input(char *);

int	main(int argc, char **argv)
{
	char		cwd[1024];
	char		input[maxcommands];
	char		*args_parsed[maxlistsize];
	char		*args_piped[maxlistsize];
	char		*user;
	int			exec_type;

	if (argc != 1)
		return (0);
	user = getenv("USER");
	printf(_cyan"@%s \n"_reset, user);
	exec_type = 0;
	while (196883) /* main loop */
	{
		getcwd(cwd, sizeof(cwd)); /* wait for user input */
		printf(_yellow "%s " _reset, cwd);
		if (get_input(input))
		{
			continue ;
		}
		exec_type = get_type(input, args_parsed, args_piped);
		printf("exec_type returns: %d \n", exec_type);
	}
	(void) argv;
}

//	utils

int	get_type(char *input, char **args_parsed, char **args_piped) // string processor.handler
{
	char		*pipe_sep_strs[2];
	int		res;

	res = check_and_store_pipe(input, pipe_sep_strs);
	print_string_pair(pipe_sep_strs);
	(void) args_parsed;
	(void) args_piped;
	return res;
}

int	check_and_store_pipe(char *s, char *pipe_sep_strs[2])
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		pipe_sep_strs[i] = strsep(& s, "|");
		if (! pipe_sep_strs[i])
			break ;
	}
	if (! pipe_sep_strs[1])
		return 0;
	return 1;
}

int	get_input(char *input)
{
	char		*buff;

	buff = readline(_green "\nschtroumpf > " _reset);
	if (!strlen(buff))
	{
		return (1);
	}
	add_history(buff); /* add_history is a readline library func */
	strcpy(input, buff);
	return (0);
}

//	debugger

void	print_string_pair(char **v)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		printf("String %0.2d: %s \n", i + 1, v[i]);
	}
}
