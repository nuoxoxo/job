#include "v6.h"

enum e_builtin	builtin_typeof(t_atom *cmd, t_token *token)
{
	print("atom.cmd: %s \n", cmd->str);
	if (cmd == null || ft_strlen(cmd->str) == 0)
		return (NONE);
	if (!ft_strcmp(cmd->str, "cd"))
		return (CD);
	if (!ft_strcmp(cmd->str, "echo"))
		return (ECHO);
	if (!ft_strcmp(cmd->str, "env"))
		return (ENV);
	if (!ft_strcmp(cmd->str, "pwd"))
		return (PWD);
	if (!ft_strcmp(cmd->str, "export"))
		return (EXPORT);
	if (!ft_strcmp(cmd->str, "unset"))
		return (UNSET);
	if (!ft_strcmp(cmd->str, "exit") && !(token->prev) && !(token->next))
		return (EXIT);
	if (!ft_strcmp(cmd->str, "exit") && (token->prev || token->next))
		return (EXIT_INSIDE_PIPE);
	return (NONE);
}

/*
enum	e_builtin
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


