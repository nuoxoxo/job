#include "Pipex.h"

void	XCQ(char *arg, char **env)
{
	char		**cmd;
	char		*path;

	cmd = ft_split(arg, ' ');
	path = path_finder(cmd[0], env);
	if (path)
	{
		if (execve(path, cmd, env) == -1)
			_exit_error_("Error on calling execve() \n");
		return ;
	}
	free_strlst(cmd);
	_exit_error_("Error on path-finding \n");
}

//	TODO

char	*path_finder(char *cmd, char **env)
{
	char		**paths;
	char		*path;
	char		*part;
	int			i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part, cmd);
		free(part);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	free_strlst(paths);
	return (0);
}

void	free_strlst(char **vect)
{
	int		i;

	if (!vect)
		return ;
	i = -1;
	while (vect[++i])
	{
		free(vect[i]);
	}
	free(vect);
}

//

void	_exit_error_(char *s)
{
	if (s)
		perror(s);
	exit(EXIT_FAILURE);
}

void	_exit_usage_(void)
{
	char		*s = "Usage: ./pipex file1 cmd1 cmd2 file2 \n";

	write(1, s, len(s));
	exit(EXIT_FAILURE);
}

int	len(char *s)
{
	int		i;

	i = 0;
	while (s[i] && ++i)
		;
	return (i);
}
