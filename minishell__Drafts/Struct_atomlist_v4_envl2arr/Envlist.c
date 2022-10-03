#include "Envlist.h"

t_env	*envp_to_envlist(char **envp)
{
	t_env		*envlist;
	t_env		*temp;
	int			i;
	int			dist_from_eq;

	envlist = NULL;
	i = 0;
	while (envp[i])
	{
		dist_from_eq = 0;
		while (envp[i][dist_from_eq] != '=')
			++dist_from_eq;
		temp = envlist_new_node(
			ft_strndup_protected(envp[i], dist_from_eq),
			ft_strdup_protected(envp[i] + dist_from_eq + 1));
		envlist_append(& envlist, temp);
		++i;
	}
	//envlist_replace(envlist, "OLDPWD", NULL);
	return (envlist);
}

//	print

void	envlist_print(t_env *envlist)
{
	if (!envlist)
		printf("(null)\n");
	while (envlist)
	{
		if (envlist->val)
			printf("%s=%s\n", envlist->key, envlist->val);
		envlist = envlist->next;
	}
}

//	init

t_env	*envlist_new_node(char *key, char *val)
{
	t_env	*res;

	res = (t_env *) malloc(sizeof(t_env));
	if (!res)
		exit_error_alloc();

	res->prev = NULL;
	res->next = NULL;
	res->key = key;
	res->val = val;

	return (res);
}

//	append

void	envlist_append(t_env **env, t_env *res)
{
	t_env	*temp;

	if (*env == NULL)
	{
		(*env) = res;
		return ;
	}
	temp = *env;
	while ((*env)->next)
	{
		*env = (*env)->next;
	}
	(*env)->next = res;
	res->prev = (*env);
	*env = temp;
}

//	pop

void	envlist_erase(t_env **env)
{
	t_env	*temp;

	temp = (*env);
	if ((*env)->prev && (*env)->next)
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		(*env) = temp->next;
	}
	else if ((*env)->prev == NULL)
	{
		(*env) = (*env)->next;
		(*env)->prev = NULL;
	}	
	else if ((*env)->next == NULL)
	{
		(*env) = (*env)->prev;
		(*env)->next = NULL;
	}
	free(temp->key);
	free(temp->val);
	temp->next = NULL;
	temp->prev = NULL;
	free(temp);
}

//	hasOwnProperty . get_key . get_val

char	*envlist_get_key(char *s)
{
	int		i;
	int		len;
	char		*key;

	len = 0;
	i = 1;
	while (s[i])
	{
		if (i == 1 && ft_isdigit(s[1]))
		{
			len++;
			break ;
		}
		else if (!ft_isalnum(s[i]) && s[i] != '_')
			break ;
		len++;
		i++;
	}
	if (s[1] == '?')
		len = 1;
	key = ft_strndup_protected(s + 1, len);
	return (key);
}

char	*envlist_get_val(t_env *node, char *key)
{
	char	*val;

	val = NULL;
	if (*key == '?')
		return (ft_itoa(g_exit_status));
	while (node)
	{
		if (!ft_strcmp(node->key, key) && node->val)
		{
			val = ft_strdup_protected(node->val);
			break ;
		}
		node = node->next;
	}
	return (val);
}

int	envlist_has_key(t_env *node, char *key)
{
	int	ok;

	ok = 0;
	while (node)
	{
		if (!ft_strcmp(node->key, key))
		{
			ok = 1;
			break ;
		}
		node = node->next;
	}
	return (ok);
}

//	replace

int	envlist_replace(t_env *head, char *to_find, char *to_set)
{
	t_env		*node;
	char		*temp;

	node = head;
	while (node)
	{
		if (!ft_strcmp(node->key, to_find))
			break ;
		node = node->next;
	}
	if (!node)
		return (0);
	temp = node->val;
	node->val = to_set;
	if (temp)
		free(temp);
	return (1);
}

//	free

void	envlist_free(t_env *env)
{
	t_env	*p;

	while (env)
	{
		p = env;
		env = env->next;
		free(p->key);
		if (p->val)
		{
			free(p->val);
		}
		p->key = NULL;
		p->val = NULL;
		p->next = NULL;
		p->prev = NULL;
		free(p);
		p = NULL;
	}
}

//	new

char	**envlist_to_arr(t_env *node)
{
	char		**arr;
	t_env		*ptr;
	int		len;

	ptr = node;
	len = 0;
	while (ptr)
	{
		ptr = ptr->next;
		++len;
	}
	arr = malloc(sizeof(char *) * (1 + len));
	if (!arr)
		exit_error_alloc();
	arr[len] = NULL;
	len = 0;
	while (node)
	{
		arr[len++] = ft_strjoin_triple(node->key, "=", node->val);
		node = node->next;
	}
	return (arr);
}
