#include "v6.h"

/*	prototype:	*/

/*
while (True)
	line = readline(prompt);
	if (line)
		if (atomlist_get(line, & atomlist, envlist))
			print_atomlist(atomlist);
		if (tokenlist_get(& tokenlist, atomlist, envlist))
			print_tokenlist(tokenlist);
*/

int	tokenlist_get(t_token **res, t_atom *head, t_env *envlist)
{
	t_token		*node;

	if (head == null)
		return (0);
	while (head)
	{
		//print(color1 "loop inside %s \n" noc, __FUNCTION__); // dbg
		if (head->type != T_PIPE)
		{
			node = tokenlist_from_envlist(envlist); /* done */
			tokenlist_from_atomlist(node, & head); /* done */
			tokenlist_append(res, node); /* done */
		}
		if (head) // debugger
			print("head.str (1): %s \n", head->str);

		if (head && head->type == T_PIPE)
			atomlist_pop(& head);

		if (head) // debugger
			print("head.str (2): %s \n", head->str); // debugger
	}
	head = null; // protection
	return (1);
}

void	tokenlist_append(t_token **head, t_token *node) // try subs head w. ptr
{
	t_token		*new_head;

	if (*head == null)
	{
		(*head) = node;
		return ;
	}
	new_head = *head;
	while ((*head)->next)
	{
		*head = (*head)->next;
	}
	(*head)->next = node;
	node->prev = (*head);
	*head = new_head;
	//print(color3 "%s success. \n" noc, __FUNCTION__); // debugger
}

void	tokenlist_from_atomlist(t_token *token, t_atom **node)
{
	int		type;

	while ((*node) && (*node)->type != T_PIPE)
	{
		type = (*node)->type;
		if ((*node)->type > T_OFF)
		{
			atomlist_pop(node);
			(*node)->type = type;
			if (type == T_REDIR_IN || type == T_HEREDOC)
			{
				atomlist_cherrypick_append(node, & (token->REDIR_IN));
			}
			else if (type == T_REDIR_OUT || type == T_APPEND)
			{
				atomlist_cherrypick_append(node, & (token->REDIR_OUT));
			}
		}
		else
		{
			atomlist_cherrypick_append(node, & (token->cmd));
		}
	}

	//print(color2 "%s success. \n" noc, __FUNCTION__); // debugger
}

//	below function: to try

/*

void	tokenlist_from_atomlist(t_token *token, t_atom *node)
{
	int		type;

	while (node && node->type != T_PIPE)
	{
		type = node->type;
		if (node->type > T_OFF)
		{
			atomlist_pop(& node);
			node->type = type;
			if (type == T_REDIR_IN || type == T_HEREDOC)
			{
				atomlist_cherrypick_append(& node, & (token->REDIR_IN));
			}
			else if (type == T_REDIR_OUT || type == T_APPEND)
			{
				atomlist_cherrypick_append(& node, & (token->REDIR_OUT));
			}
		}
		else
		{
			atomlist_cherrypick_append(& node, & (token->cmd));
		}
	}
}
*/

t_token		*tokenlist_from_envlist(t_env *elst) // init to an empty tokenlist
{
	t_token		*node;

	node = (t_token *) malloc(sizeof(t_token));
	if (node == null)
		exit_error_alloc();
	node->envlist = elst;
	node->cmd = null;
	node->prev = null;
	node->next = null;
	node->REDIR_IN = null;
	node->REDIR_OUT = null;
	//print("%s success. \n", __FUNCTION__); // debugger
	return (node);
}

void	tokenlist_free(t_token *head)
{
	t_token		*temp;

	while (head)
	{
		temp = head;
		head = head->next;
		atomlist_free(temp->cmd);
		atomlist_free(temp->REDIR_IN);
		atomlist_free(temp->REDIR_OUT);
		free(temp);
		temp = null;
	}
	head = null;
}
