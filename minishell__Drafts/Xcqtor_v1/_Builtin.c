#include "v6.h"

/*

	◦ echo 	with option ’-n’			. Done
	◦ cd 	with only a relative or absolute path
	◦ pwd 	without any options			. Done
	◦ export without any option			. Done 
	◦ unset without any options			. Done
	◦ env 	without any options and any arguments	. Done
	◦ exit 	without any options			. DONE

*/

void	builtin_atom_xcq(t_env *envl, t_atom *atom, enum e_btn_type type)
{
	print(color2 "typeof single builtin: %d " noc nl, type);
	if (type == PWD)
		builtin_pwd();
	if (type == ECHO)
		builtin_echo(atom->next);
	if (type == ENV)
		builtin_env(atom, envl);
	if (type == UNSET)
		builtin_unset(atom, envl);
	if (type == EXPORT)
		builtin_export(atom, envl);
	if (type == CD)
		builtin_cd(atom, envl);
	if (type == EXIT)
		builtin_exit(atom, EXIT);
	if (type == EXIT_INSIDE_PIPE)
		builtin_exit(atom, EXIT_INSIDE_PIPE);

	(void) envl;
	(void) atom;
}

void	builtin_atom(t_env *envlist, t_token *node, enum e_btn_type type)
{
	int		cin;
	int		cout;

	// if ( !check_io_file(tokenlist)) /// done . put temporarily in main
	// 	return ;

	cin = dup(STDIN_FILENO);
	cout = dup(STDOUT_FILENO);

	redirection_config(node); // done
	builtin_atom_xcq(envlist, node->cmd, type); // todo . now has cd

	dup2(cin, STDIN_FILENO);
	dup2(cout, STDOUT_FILENO);
}

enum	e_btn_type builtin_typeof(t_atom *atom, t_token *token)
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

