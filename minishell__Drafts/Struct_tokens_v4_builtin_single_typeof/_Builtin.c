#include "v6.h"

void	builtin_atom(t_env *envlist, t_token *node, enum e_btn_type type)
{
	int		cin;
	int		cout;

	// if ( !check_io_file(tokenlist)) /// done . put temporarily in main
	// 	return ;

	cin = dup(STDIN_FILENO);
	cout = dup(STDOUT_FILENO);

	redirection_config(node); // done
	builtin_atom_xcq(envlist, node->cmd, type); // todo . now only a DBG

	dup2(cin, STDIN_FILENO);
	dup2(cout, STDOUT_FILENO);
}

void	builtin_atom_xcq(t_env *envl, t_atom *atom, enum e_btn_type type)
{
	print(color2 "single builtin xcq type: %d " noc nl, type);
	print_builtin_type(type);

	(void) envl;
	(void) atom;
}

enum e_btn_type	builtin_typeof(t_atom *atom, t_token *token)
{
	print("atom.cmd: %s \n", atom->str);
	if (atom == null || ft_strlen(atom->str) == 0)
		return (NONE);
	if (!ft_strcmp(atom->str, "cd"))
		return (CD);
	if (!ft_strcmp(atom->str, "echo"))
		return (ECHO);
	if (!ft_strcmp(atom->str, "env"))
		return (ENV);
	if (!ft_strcmp(atom->str, "pwd"))
		return (PWD);
	if (!ft_strcmp(atom->str, "export"))
		return (EXPORT);
	if (!ft_strcmp(atom->str, "unset"))
		return (UNSET);
	if (!ft_strcmp(atom->str, "exit") && !(token->prev) && !(token->next))
		return (EXIT);
	if (!ft_strcmp(atom->str, "exit") && (token->prev || token->next))
		return (EXIT_INSIDE_PIPE);
	return (NONE);
}

/*
enum	e_btn_type
{
	NONE, //
	CD, //
	ECHO, //
	ENV, //
	PWD, // 
	EXPORT, // 
	UNSET, // 
	EXIT, //
	EXIT_INSIDE_PIPE //
};
*/
