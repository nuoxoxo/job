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
/* ****************************************************************** nuo *** */

#include "Simple_shell.h"

int			g_history_wait[10];
int			g_buff_head = 1;

int	main(int argc, char *argv[])
{
	char		*args[Max_args / 2 + 1];

	init_history();
	while (196883)
	{
		prompt;
		fflush(stdout);

		char		cmd_line[Max_args + 1];
		char		**aptr; // argv pointer
		char		*sptr;
		pid_t		pid;
		int		vi;
		int		to_wait;

		if (scanf("%[^\n]%*1[\n]", cmd_line) < 1)
		{
			if (scanf("%1[\n]", cmd_line) < 1)
				return (stdin_error, 1);
			continue ;
		}
		sptr = cmd_line;
		while ((*sptr == ' ' || *sptr == '\t') && ++sptr)
			;
		vi = 0;
		while(*sptr != '\0')
		{
			char		*temp_buff;
			int			ret;

			temp_buff = malloc((Max_args + 1));
			args[vi] = malloc((Max_args + 1));
			ret = sscanf(sptr, "%[^ \t]", args[vi]);
			sptr += strlen(args[vi]);
			if(ret < 1)
			{
				return (invalid_cmd, 1);
			}
			ret = sscanf(sptr,"%[ \t]", temp_buff);
			if(ret > 0)
			{
				sptr += strlen(temp_buff);
			}
			++vi;
			free(temp_buff);
		}
		to_wait = 1;
		if (strlen(args[vi - 1]) == 1 && args[vi - 1][0] == '&')
		{
			free(args[vi - 1]);
			args[vi - 1] = NULL;
			to_wait = 0;
		}
		else
		{
			args[vi] = NULL;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			return (free_history(), 0);
		}

		//	history computation

		if (args[1] == NULL && strcmp(args[0], "history") == 0)
		{
			show_history();
			continue ;
		}
		aptr = history_computation(args, & to_wait);

		//	fork child to Execute args

		if ((pid = fork()) < 0)
			return (fork_error, 1);
		else if (! pid)
		{
			if (execvp(aptr[0], aptr))
			{
				return (invalid_cmd, 1);
			}
		}
		else
		{
			if (to_wait)
			{
				while (wait(NULL) != pid)
					;
			}
			else
			{
				printf("[1]%d\n", pid);
			}
		}
	}
//	critical codeblock ends here
	(void) argc;
	(void) argv;
}

/*
 *	history
 */

void	init_history(void)
{
	int		i;
	int		j;

	i = -1;
	while (++i < Max_pair)
	{
		j = -1;
		while (++j < Max_args / 2 + 1)
		{
			history[i][j] = NULL;
		}
		g_history_wait[i] = 0;
	}
}

char	**history_computation(char **args, int *to_wait)
{
	char		*sptr;
	int			index;
	int			i;

	if (strcmp(args[0], "!!") == 0 && !args[1])
	{
		if (g_buff_head > 0)
		{
			strcpy(args[0], history[(g_buff_head - 1) % 10][0]);
			i = 0;
			while (history[(g_buff_head - 1) % 10][++i] != NULL)
			{
				args[i] = malloc((Max_args + 1) * sizeof(char));
				strcpy(args[i], history[(g_buff_head - 1) % 10][i]);
			}
			args[i] = NULL;
			*to_wait = g_history_wait[(g_buff_head - 1) % 10];
		}
		else
		{
			return (history_empty, args);
		}
	}
	else if (args[0][0] == '!' && !args[1])
	{
		sptr = &(args[0][1]);
		if (sscanf(sptr, "%d", & index) == 1)
		{
			if (index > 0 && g_buff_head > index - 1 && index > g_buff_head - 9)
			{
				strcpy(args[0], history[(index - 1) % 10][0]);
				i = 0;
				while (history[(index - 1) % 10][++i] != NULL)
				{
					args[i] = malloc((Max_args + 1) * sizeof(char));
					strcpy(args[i], history[(index - 1) % 10][i]);
				}
				args[i] = NULL;
				*to_wait = g_history_wait[(index - 1) % 10];
			}
			else
			{
				return (history_ioor, args);
			}
		}
		else
		{
			return (history_invi, args);
		}
	}
	i = -1;
	while (++i < Max_args / 2 + 1 && history[g_buff_head % 10][i] != NULL)
	{
		free(history[g_buff_head % 10][i]);
	}
	i = -1;
	while (args[++i] != NULL)
	{
		history[g_buff_head % 10][i] = args[i];
	}
	history[g_buff_head % 10][i] = args[i];
	g_history_wait[g_buff_head % 10] = *to_wait;

	return (history[(g_buff_head++) % 10]);
}

/*
 * 	cleaner
 */

void	free_history(void)
{
    	int		i;
	int		j;

	i = -1;
	while (++i < Max_pair && i < g_buff_head)
	{
		j = -1;
		while (history[i][++j] != NULL)
			if(history[i][j])
				free(history[i][j]);
	}
}

void	show_history(void)
{
	int		index;
	int		i;
	int		j;

	i = -1;
	while (++i < Max_pair && i < g_buff_head)
	{
		if (g_buff_head > Max_pair)
		{
			index = g_buff_head + i - 9;
		}
		else
		{
			index = i + 1;
		}
		printf("[%d] ", index);
		j = -1;
		while (history[(index - 1) % 10][++j] != NULL)
		{
			printf("%s ", history[(index - 1) % 10][j]);
		}
		if (g_history_wait[(index - 1) % 10] == 0)
		{
			printf("& ");
		}
		endl;
	}
}

void	show_argv(int c, char *v[])
{
	int		i;

	i = 0;
	while (++i < c)
		printf("%s \n", v[i]);
	if (i == 1)
		printf("(empty) \n");
}
