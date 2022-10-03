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

#include "space_parser.hpp"

/*	debugger	*/
void	print_string_array(char **);
void	print_string_pair(char **);
/*	utils	*/
void	parse_space(char *, char **);
int	check_and_parse_pipe(char *, char *_[2]);
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

		/* get execution type */
		
		printf(_green "pipe parsed: \n" _reset);
		exec_type = get_type(input, args_parsed, args_piped);
		printf(_green "args parsed: \n" _reset);
		print_string_array(args_parsed);
		printf(_green "args piped: \n" _reset);
		print_string_array(args_piped);

	}
	(void) argv;
}

//	utils

int	get_type(char *input, char **args_parsed, char **args_piped) // string processor.handler
{
	// not just check but store the piped string <- has_pipe <- parse_pipe
	char		*pipe_sep_strs[2];
	int		has_pipe;

	has_pipe = check_and_parse_pipe(input, pipe_sep_strs);
	print_string_pair(pipe_sep_strs);
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
	return has_pipe;
}

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

	buff = readline(_green "\nschtroumpf> " _reset);
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

	i = -1;
	while (++i < maxlistsize)
	{
		if (v[i] == NULL)
			break ;
		printf("String %0.2d: %s \n", i + 1, v[i]);
	}
	printf(_mag "- \n" _reset);
}

void	print_string_pair(char **v)
{
	int		i;

	i = -1;
	while (++i < 2)
	{
		printf("String %0.2d: %s \n", i + 1, v[i]);
	}
	printf(_mag "- \n" _reset);
}
