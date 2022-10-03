#include "v6.h"

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 
◦ export without any options	::: Here :::
◦ unset without any options 
◦ env 	without any options and any arguments 
◦ exit 	without any options 
*/

static void	builtin_export_insert(char *s, int index, t_env *e);
static void	builtin_export_print_env(t_env *e);
static void	builtin_export_on_failure(char *s);
static	int	builtin_export_index_of_equal(char *s);

void	builtin_export(t_atom *node, t_env *e)
{
	int		index_of_eq;

	if (node->next == null)
		builtin_export_print_env(e);
	node = node->next;
	while (node)
	{
		index_of_eq = builtin_export_index_of_equal(node->str);
		if (index_of_eq != 0)
			builtin_export_insert(node->str, index_of_eq, e);
		else if (index_of_eq == 0)
			builtin_export_on_failure(node->str);
		node = node->next;
	}
}

static int	builtin_export_index_of_equal(char *s)
{
	int		i;

	i = 0;
	if (ft_isdigit(s[i]))
		return (0);
	while (s[i] != '\0' && s[i] != '=')
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
			return (0);
		i++;
	}
	return (i);
}

static void	builtin_export_insert(char *line, int offset, t_env *e)
{
	char	*key;
	char	*val;

	key = ft_strndup_protected(line, offset);
	if (line[offset] != '\0')
	{
		val = ft_strdup_protected(line + offset + 1);
	}
	else
	{
		val = null;
	}
	if (val == null || !envlist_has_key(e, key))
	{
		envlist_append(& e, envlist_new_node(key, val));
	}
	else
	{
		envlist_replace(e, key, val);
		free(key);
	}
	/*if (key)
		free(key);
	if (val)
		free(val);*/
}

//	below buggy free because envlist_replace and append will point to 
//	key & val, and will not malloc a new char*
//	thus, can't free here

/*
static void	builtin_export_insert(char *line, int offset, t_env *e)
{
	char	*key;
	char	*val;

	key = ft_strndup_protected(line, offset);
	if (line[offset] != '\0')
	{
		val = ft_strdup_protected(line + offset + 1);
	}
	else
	{
		val = null;
	}
	if (val == null || !envlist_has_key(e, key))
	{
		envlist_append(& e, envlist_new_node(key, val));
	}
	else
	{
		envlist_replace(e, key, val);
	}
	if (key)
		free(key);
	if (val)
		free(val);
}
*/

static void	builtin_export_print_env(t_env *e)
{
	while (e)
	{
		if (e->val)
		{
			ft_putstr_fd("declare -x ", STDOUT_FILENO);
			ft_putstr_fd(e->key, STDOUT_FILENO);
			ft_putstr_fd("=\"", STDOUT_FILENO);
			ft_putstr_fd(e->val, STDOUT_FILENO);
			ft_putstr_fd("\"", STDOUT_FILENO);
		}
		ft_putstr_fd("\n", STDOUT_FILENO);
		e = e->next;
	}
}

static void	builtin_export_on_failure(char *arg)
{
	char		*obj;

	if (!arg)
	{
		return ;
	}
	obj = ft_strjoin_triple("minishell: export: `", arg,
			"': not a valid identifier \n");
	ft_putstr_fd(obj, STDERR_FILENO);
	g_exit_status = 1;
	free(obj);
}
