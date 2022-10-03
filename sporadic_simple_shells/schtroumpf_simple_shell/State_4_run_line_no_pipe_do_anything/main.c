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
void	print_string_array(char **);
void	print_string_pair(char **);
/*	utils	*/
void	parse_space(char *, char **);
int	check_and_parse_pipe(char *, char *_[2]);
int	get_type(char *, char **, char **);
int	get_input(char *);
int	run_builtin(char **cmdstring);
void	run_line(char **);

extern char	**environ;

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
		printf(_yellow "%s \n" _reset, cwd);
		if (get_input(input))
		{
			continue ;
		}
		// process the input ↓↓↓
		exec_type = get_type(input, args_parsed, args_piped); 
		// proceed to execute builtin, incl. command not found ↓↓↓
		if (!exec_type)
			;
		if (exec_type == 1)
		{
			run_line(args_parsed); // type 1: a simple command
		}
		/*
		if (exec_type == 2) 
		{
			// TODO
			run_pipe(args_piped); // type 2: involves a pipe
		}
		*/
	}
	(void) argv;
	return (0);
}

/*	get_type	*/

int	get_type(char *input, char **args_parsed, char **args_piped) // string processor.handler
{
	// not just check but store the piped string <- has_pipe <- parse_pipe
	char		*pipe_sep_strs[2];
	int		has_builtin;
	int		has_pipe;

	has_pipe = check_and_parse_pipe(input, pipe_sep_strs);

	//print_string_pair(pipe_sep_strs);
	/* debugger */
	
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

/*	do simple line / args	*/
//	Model : exec_line(args_parsed); // type 1: a simple command

void	run_line(char **lines)
{
	pid_t		pid;

	pid = fork();
	if (pid == -1)
	{
		printf("Error: Failed to fork child process. \n");
		return ;
	}
	if (! pid)
	{
		printf( _mag "in the child now. command: %s \n" _reset , lines[0]);
		print_string_array(lines);
		if (execvp(lines[0], lines) < 0)
			printf("Error: Could not execute command '%s' \n",
				lines[0]);
		return ; // return or exit ??
		//exit(0) ; // return or exit ??
	}
	wait(NULL);
	return ;
}

/*	do built-ins		*/

int	run_builtin(char **cmdstring) // ---> handle buildin else do nothing
{
	//int			total_cmds_to_handle = 3;
	int			total_cmds_to_handle = 2;
	int			i;
	char		*cmds[total_cmds_to_handle];
	//char		cwdtopwd[100];

	cmds[0] = "exit";
	cmds[1] = "cd"; // somehow run_line cant do `cd __arg__` so we keep it here
	i = -1;
	while (++i < total_cmds_to_handle) // lookup in cmds list
	{
		if (strcmp(cmdstring[0], cmds[i]) == 0)
			break ;
	}
	if (i == 0) // exit
	{
		printf("Saving session...completed.\n\n[Process completed]\n");
		exit(0);
	}
	if (i == 1) // cd
	{
		chdir(cmdstring[1]);
		return 1;
	}
	if (i > total_cmds_to_handle - 1) // nosajthing
	{
		;
		// Should do nothing now that we allowed 
		// execvp to do more cmds.
		//printf("schtroumpf: command not found: %s \n", cmdstring[0]);
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
