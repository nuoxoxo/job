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

#include "minishell.h"

t_command_line	*command_line_create(t_command_line *line);
void		command_line_input_error(void);
void		command_line_free(t_command_line *);
void		void_star_free(void *);
void		env_free(void);
void		token_free(t_token *node);

void	start_shell(char **env)
{
	t_command_line		*line;

	line = command_line_create(NULL); // . done
	print("you're in the shell. \n");
	while ((int) 1e9)
	{
		line->input = readline("minishell > ");
		if (line->input == NULL)
		{
			command_line_input_error(); // . done
			break ;
		}
		if (strcmp(line->input, ""))
		{
			printf("everything in its right place. \n"); // testing
			// lexer . parser // TODO
		}
		command_line_free(line); // . done
		line = command_line_create(NULL);
	}
	(void) env;
}

/*	create and append command line node	*/

t_command_line	*command_line_create(t_command_line *node)
{
	t_command_line		*empty; /// tail

	/* tail: an empty node to follow the passed-in node */

	empty = malloc(sizeof(t_command_line));
	if (empty == NULL)
		return (NULL);
	empty->input = NULL;
	empty->next = NULL;
	if (node == NULL)
	{
		empty->prev = NULL;
		empty->next = NULL;
	}
	else
	{
		node->next = empty;
		empty->prev = node;
	}
	
	empty->token = NULL; // ------> to delete
	//empty->token = token_create(NULL); // TODO

	return (empty);
}

/*		free command line node		*/

void	command_line_free(t_command_line *line)
{
	if (line->input)
	{
		free(line->input);
	}
	if (line->token)
	{
		token_free(line->token); // . done
	}
	if (line->cmd)
	{
		;
		//cmd_free(line->cmd); // TODO
	}
	void_star_free(line); // . done
}

/*		command line parser on Err		*/

void	command_line_input_error(void)
{
	ft_putstr_fd("exit \n", 2);
	env_free(); // . done
}

/*		env_free		*/

void	env_free(void)
{
	/*
	t_env		**e;
	t_env		*head; // slow ptr
	t_env		*tail; // fast ptr

	//e = get_env(NULL); // TODO
	head = *e;
	while (head)
	{
		tail = head->next;
		free(head->cont);
		free(head);
		head = next;
	}
	*/
}

/*		free tokens		*/

void	token_free(t_token *node)
{
	t_token		*p;

	while (node->prev)
	{
		node = node->prev;
	}
	while (node)
	{
		if (node->cont)
		{
			void_star_free(node->cont);
		}
		p = node;
		node = node->next;
		if (p)
		{
			void_star_free(p);
		}
	}
}

/*		void_star_free		*/

void	void_star_free(void *cont)
{
	if (!cont)
		return ;
	free(cont);
	cont = NULL;
}
