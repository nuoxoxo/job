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


/*	utils	*/
void	parse_space(char *, char **);
int	check_and_parse_pipe(char *, char *_[2]);
int	get_type(char *, char **, char **);
int	get_input(char *);
int	run_builtin(char **cmdstring);
/*	debugger	*/
void	print_string_array(char **);
void	print_string_pair(char **);


extern char	**environ; /* needed by execve, for envlist access outside of main */


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
	printf(_yellow "%s \n" _reset, getcwd(cwd, sizeof(cwd)));
	exec_type = 0;
	while (196883) /* main loop */
	{
		if (get_input(input))
		{
			continue ;
		}
		// process the input ↓↓↓
		exec_type = get_type(input, args_parsed, args_piped); 
		// proceed to execute builtin, incl. command not found ↓↓↓
		if (!exec_type)
			;

	}
	(void) argv;
	return (0);
}

int	get_type(char *input, char **args_parsed, char **args_piped) // string processor.handler
{
	char		*pipe_sep_strs[2];
	int		has_builtin;
	int		has_pipe;

	has_pipe = check_and_parse_pipe(input, pipe_sep_strs);
	//print_string_pair(pipe_sep_strs); /* debugger */
	if (has_pipe)
	{
		parse_space(pipe_sep_strs[0], args_parsed); // left of pipe
		parse_space(pipe_sep_strs[1], args_piped); // right of pipe
	}
	else
	{
		parse_space(input, args_parsed);
	}
	has_builtin = run_builtin(args_parsed);
	if (! has_builtin)
		return (has_pipe + 1);
		// return 1* if is a builtin w/o pipe else 2* if builtin + pipe
	return (0);
	// builtin has been checked and dealt with whether builtin exists or not
}

int	run_builtin(char **cmdstring)
{
	int			total_cmds_to_handle = 3;
	int			i;
	char		cwdtopwd[100];
	char		*cmds[total_cmds_to_handle];

	cmds[0] = "exit";
	cmds[1] = "pwd";
	cmds[2] = "cd";
	i = -1;
	while (++i < total_cmds_to_handle)
	{
		if (strcmp(cmdstring[0], cmds[i]) == 0)
			break ;
	}
	if (i == 0)
	{
		printf("Saving session...completed.\n\n[Process completed]\n");
		exit(0);
	}
	else if (i == 1)
	{
		print_string_array(cmdstring); // debugged
		print_string_array(environ); // debugged
		printf("%s \n", getcwd(cwdtopwd, 100));
		// so strange: 
		// we use `cwd` instead of `execve` to do `pwd`
		// line below is not working
		// if (execve("/bin/pwd", argp, environ) == -1) {
		// 	printf("err\n");
		// }

		return 1;
	}
	else if (i == 2)
	{
		chdir(cmdstring[1]);
		return 1;
	}
	else if (i > total_cmds_to_handle - 1)
	{
		printf("schtroumpf: command not found: %s \n", cmdstring[0]);
	}
	return 0;
}

/*	parsers		*/

void	parse_space(char *s, char **v)
{
	int		i;

	i = 0;
	while (i < maxlistsize)
	{
		v[i] = strsep(& s, " ");
		if (!v[i])
			break ;
		if (strlen(v[i]) == 0) // avoid empty string
			--i;
		++i;
	}
}

int	check_and_parse_pipe(char *s, char *pipe_sep_strs[2])
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

	buff = readline(_green "schtroumpf> " _reset);
	if (!strlen(buff))
	{
		return (1);
	}
	add_history(buff); /* readline library func */
	strcpy(input, buff);
	return (0);
}

//	debugger

void	print_string_array(char **v)
{
	int		i;

	printf( _cyan "Printing your cmd args: \n" _reset );
	i = -1;
	while (++i < maxlistsize)
	{
		if (v[i] == NULL)
			break ;
		printf(" String %0.2d: %s \n", i + 1, v[i]);
	}
	printf(_mag "- \n" _reset);
}

void	print_string_pair(char **v)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		printf(" String %0.2d: %s \n", i + 1, v[i]);
	}
}
