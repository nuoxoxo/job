#include "v6.h"

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 
◦ export without any options 
◦ unset without any options	::: Here ::: 
◦ env 	without any options and any arguments 
◦ exit 	without any options 
*/

static int			builtin_unset_isvalid(char *key);
static void		builtin_unset_on_success(char *, t_env *it);
static void		builtin_unset_on_failure(char *);

void	builtin_unset(t_atom *a, t_env *e)
{
	if (!(a->next))
		return ;
	a = a->next;
	while (a)
	{
		if (builtin_unset_isvalid(a->str))
		{
			print(color0 "unset key %s: success \n" noc, a->str); // DBG
			builtin_unset_on_success(a->str, e);
		}
		else
		{
			print(color0 "unset key %s: failure \n" noc, a->str); // DBG
			builtin_unset_on_failure(a->str);
		}
		a = a->next;
	}
}

static void		builtin_unset_on_failure(char *key)
{
	char		*obj;

	if (!key)
	{
		return ;
	}
	obj = ft_strjoin_triple("minishell: unset: `", key, 
			"': not a valid identifier \n");
	ft_putstr_fd(obj, STDERR_FILENO);
	free(obj);
	g_exit_status = 1;
}

static void		builtin_unset_on_success(char *key, t_env *it)
{
	while (it && ft_strcmp(it->key, key))
	{
		it = it->next;
	}
	if (it)
	{
		envlist_erase(& it);
	}
}

//	1st check:	! leading number except _
//	2nd check:  ! non alpha numeric except _

static int		builtin_unset_isvalid(char *str)
{
	if (!ft_isalpha(*str) && *str != '_') // ! leading number except _
		return (0);
	while (*str)
	{
		if (!ft_isalnum(*str) && *str != '_') // ! non alpha numeric except _
			return (0);
		str++;
	}
	return (1);
}
