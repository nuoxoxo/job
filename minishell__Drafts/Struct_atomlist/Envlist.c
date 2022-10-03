#include "Envlist.h"

t_env	*envp_to_envlist(char **envp)
{
	t_env		*envlist;
	t_env		*temp;
	int		i, id; // index & index of '=' the env delimiter

	envlist = NULL;
	i = 0;
	while (envp[i])
	{
		id = 0;
		while (envp[i][id] != '=')
			++id;
		temp = envlist_new_node(
			sndup2(envp[i], id),
			sdup2(envp[i] + id + 1));
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
		err_alloc();

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

//	insert . get_key . get_val . all NEW

char	*envlist_insert(t_env *envlist, char *atomstr, char *afterdollor)
{
	int		len;
	int		i; // i is a pointer to find '$'
	char		*key;
	char		*val;
	char		*res;

	printf( color1 "here: envlst insert, upper \n" noc );

	//key = get_env_key(str);

	key = envlist_get_key(afterdollor); // envlist_get_key . done
	len = slen(key);
	i = 0;
	while (atomstr[i] && atomstr[i] != '$' && ++i) ;
	if (len == 0 && ft_strcmp(atomstr + i, "$") == 0)
	{
		free(key);
		return (atomstr);
	}

	printf( color1 "here: envlst insert, middle \n" noc );

	//val = get_env_val(envlist, env_key); 
	val = envlist_get_val(envlist, key); // envlist_get_val . done

	if (atomstr[i] == '$' && atomstr[i + 1] && atomstr[i + 1] == '$'
		&& ++i){;}
	res = ft_strjoin2(sndup2(atomstr, i), val);
	res = ft_strjoin2(res, sdup2(atomstr + i + len + 1));
	free(atomstr);
	free(key);

	printf( color1 "here: envlst insert, lower \n" noc );

	return (res);
}

char	*envlist_get_key(char *s)
{
	int		i;
	int		len;
	char		*key;

	len = 0;
	i = 1;
	while (s[i])
	{
		if (i == 1 && ft_isdigit(s[1])) // TODO
		{
			len++;
			break ;
		}
		else if (!ft_isalnum(s[i]) && s[i] != '_') // TODO
			break ;
		len++;
		i++;
	}
	if (s[1] == '?')
		len = 1;
	key = sndup2(s + 1, len);
	return (key);
}

char	*envlist_get_val(t_env *envlist, char *key)
{
	char	*val;

	val = NULL;
	if (*key == '?')
		return (ft_itoa(g_exit_status)); // TODO
	while (envlist)
	{
		if (!ft_strcmp(envlist->key, key) && envlist->val)
		{
			val = sdup2(envlist->val);
			break ;
		}
		envlist = envlist->next;
	}
	return (val);
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
		return (0); // key not found
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
