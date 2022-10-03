#include "v6.h"

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path	::: Here :::
◦ pwd 	without any options 
◦ export without any options 
◦ unset without any options
◦ env 	without any options and any arguments 
◦ exit 	without any options 
*/

#define NOT_SET 1
#define NOT_DIR 2
#define NOT_FOUND 3

static int		builtin_cd_oldpwd(t_env *e);
static int		builtin_cd_path(char *path, int type);
static int		builtin_cd_from_home(char *path, t_env *e);
static void		builtin_cd_error(char *msg, int err);

void	builtin_cd(t_atom *atom, t_env *e)
{
	int		ok;

	ok = 1;
	if (atom->next == null)
		ok = builtin_cd_from_home(null, e);
	else
	{
		atom = atom->next;
		if (ft_strcmp(atom->str, "-") == 0)
			ok = builtin_cd_oldpwd(e);
		else if (atom->str[0] == '~' || !ft_strcmp(atom->str, "--"))
			ok = builtin_cd_from_home(atom->str, e);
		else if (atom->type == T_ENV && !atom->str[0])
			ok = builtin_cd_from_home(null, e);
		else if ((atom->type == T_ENV && !atom->str[0]) || atom->type == T_OFF)
			ok = builtin_cd_path(atom->str, atom->type);
	}
	if (ok)
	{
		envlist_replace(e, "OLDPWD", envlist_get_val(e, "PWD"));
		envlist_replace(e, "PWD", getcwd(0, LENGTH));
	}
}

//	helper

static int	builtin_cd_oldpwd(t_env *e)
{
	char	*path;

	path = envlist_get_val(e, "OLDPWD");
	print(color1 "Try cd old pwd: %s " noc nl2, path); // DBG
	if (path && chdir(path) != -1)
	{
		ft_putendl_fd(path, STDOUT_FILENO);
		free(path);
	}
	else
	{
		builtin_cd_error("OLDPWD", NOT_SET);
	}
	if (g_exit_status != 0)
		return (0);
	return (1);
}

static int	builtin_cd_from_home(char *s, t_env *e)
{
	char	*path;

	path = envlist_get_val(e, "HOME");
	if (!path)
	{
		builtin_cd_error("HOME", NOT_SET);
		return (0);
	}
	if (s && s[0] == '~' && s[1])
	{
		path = ft_strjoin_protected(path, ft_strdup_protected(s + 1));
		print(color1 "Path from home: %s " noc nl2, path); // DBG
	}
	if (chdir(path) == -1)
	{
		builtin_cd_error(path, NOT_FOUND);
	}
	free(path);
	if (g_exit_status != 0)
		return (0);
	return (1);
}

static int	builtin_cd_path(char *s, int type)
{
	char			*path;
	struct stat		info;

	path = null;
	if (type == T_OFF || type == T_ENV)
	{
		path = ft_strdup_protected(s);
	}
	print(color1 "Try cd to path: %s " noc nl2, path); // DBG
	if (chdir(path) == -1)
	{
		if (stat(path, & info) != -1 && info.st_mode != S_IFDIR)
			builtin_cd_error(path, NOT_DIR);
		else
			builtin_cd_error(path, NOT_FOUND);
	}
	free(path);
	if (g_exit_status != 0)
		return (0);
	return (1);
}

static void	builtin_cd_error(char *msg, int err)
{
	char		*res;

	res = ft_strjoin_triple(PROMPT, "cd: ", msg);
	ft_putstr_fd(res, STDERR_FILENO);
	if (err == NOT_FOUND)
	{
		ft_putstr_fd(": No such file or directory \n", STDERR_FILENO);
	}
	else if (err == NOT_DIR)
	{
		ft_putstr_fd(": Not a directory \n", STDERR_FILENO);
	}
	else if (err == NOT_SET)
	{
		ft_putstr_fd(" not set \n", STDERR_FILENO);
	}
	g_exit_status = 1;
	if (res)
		free(res);
}
