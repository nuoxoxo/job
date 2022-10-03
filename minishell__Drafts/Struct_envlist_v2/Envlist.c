#include "Envlist.h"

t_env	*envp_to_envlist(char **envp)
{
	t_env		*envlist;
	t_env		*temp;
	int		i, dist; // index & index of '=' the env delimiter

	envlist = NULL;
	i = 0;
	while (envp[i])
	{
		dist = 0;
		while (envp[i][dist] != '=')
			++dist;
		temp = envlist_new_node(
			sndup2(envp[i], dist),
			sdup2(envp[i] + dist + 1));
		printf(color1 "%s " noc, sndup2(envp[i], dist));
		printf(" ~>  "); // NO Print in this version
		printf(color2 "%s \n" noc, sdup2(envp[i] + dist + 1));
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
