#include "v6.h"

/*
typedef struct	s_atom
{
	char			*str;
	struct	s_atom		*prev;
	struct	s_atom		*next;
	enum	e_cmd_type		type;
}	t_atom;

typedef struct	s_token
{
	int			pipe_fd[2];
	pid_t			pid;
	t_env			*envlist;
	t_atom			*cmd;
	t_atom			*REDIR_IN;
	t_atom			*REDIR_OUT;
	struct	s_token		*prev;
	struct	s_token		*next;
}	t_token ;
*/

void	print_tokenlist(t_token *node)
{
	int		i;

	print( color0 "\n(Printing tokenlist, starts) " noc nl2 );
	if (!node)
	{
		print("(null)");
		print( color0 "\n(Printing tokenlist, ends)" noc nl2 );
		return ;
	}
	i = 0;
	while (node)
	{
		print("node no.%d \n Atom.cmd: ", ++i);
		print_atom(node->cmd);
		// print_atomlist(node->cmd); // wonder if should print list

		print(" Atom.Redir_In: ");
		print_atom(node->REDIR_IN);

		print(" Atom.Redir_Out: ");
		print_atom(node->REDIR_OUT);

		if (node->next)
			print("\n");
		node = node->next;
	}
	print( color0 "\n(Printing tokenlist, ends)" noc nl2 );
}

void	print_atomlist(t_atom *node)
{
	print( color0 "(Printing atomlist starts) " noc nl2 );
	if (!node)
	{
		print("(null)");
		print( color0 "\n(Printing atomlist ends)" noc nl2 );
		return ;
	}
	while (node)
	{
		print( color1 "(type: %d) " noc , node->type);
		print( color2 "%s " noc , node->str);
		if (node->next)
			print("\n");
		node = node->next;
	}
	print( color0 "\n(Printing atomlist ends)" noc nl2 );
}

void	print_atom(t_atom *node)
{
	print( color3 "(Printing an atom) " noc);
	if (!node)
	{
		print("(null)\n");
		return ;
	}
	print( color1 "(type: %d) " noc , node->type);
	print( color2 "%s " noc nl, node->str);
}

//	printer-debuggers

void	print_char_star_array(char **arr)
{
	int		i;

	if (!(*arr))
		return ;
	i = 0;
	while (arr[i])
		print(color3 " %s \n" noc, arr[i++]);
	nl;
}

void	print_invalid_quote(int sq, int dq)
{
	print(color1 "\nquotes not valid\n('): %d\n(\"): %d\n\n" noc, sq, dq);
}

void	print_input(char *line)
{
	print("Input : " color1 "%s " noc nl, line);
	print("Length: " color2 "%d " noc nl2, (int)ft_strlen(line));
}

void	print_builtin_type(enum e_btn_type b)
{
	print( color1 "builtin type: " noc);
	if (b == 0)
		print("None ");
	if (b == 1)
		print("pwd ");
	if (b == 2)
		print("env ");	
	if (b == 3)
		print("echo ");
	if (b == 4)
		print("cd ");
	if (b == 5)
		print("export ");
	if (b == 6)
		print("unset ");
	if (b == 7)
		print("exit ");
	if (b == 8)
		print("exit pipe ");
	print(nl color0 "(check if above line matches your input)" nl);
}

//	deprecated

/*
void	print_default_type_enum(void)
{
	printf("\n- \n");
	printf("1 : T_ENV \n");
	printf("2 : T_OFF \n");
	printf("3 : T_PIPE \n");
	printf("4 : T_REDIR_IN \n");
	printf("5 : T_REDIR_OUT \n");
	printf("6 : T_APPEND \n");
	printf("7 : T_HEREDOC \n");
	printf("- \n");
}
*/
