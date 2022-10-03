#include "v6.h"

//	new . xcp

/*
void	ft_free_string_grid(char **argv)
{
	int		i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}
*/

/*
void	exit_if_path_error(char *path, struct stat info, char *command)
{
	if (!path || info.st_mode == S_IFDIR)
		exit_error_message(command);
}
*/

//	new: stderr printer exiter

void	exit_error_message(char *message)
{
	int		code;

	ft_putstr_fd(PROMPT, STDERR_FILENO);
	ft_putstr_fd(message , STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	code = 0;
	if (errno)
	{
		code = errno % 256;
		ft_putendl_fd(strerror(code), STDERR_FILENO); // strerror > string.h
	}
	exit (code);
}

/*
 *	255* => Exit status out of range
 * 
 *	out of range exit values can result in unexpected exit codes. 
 *	an exit value greater than 255 returns an exit code modulo 256. 
 *	eg., exit 3809 gives an exit code of 225 (3809 % 256 = 225).
 *
 *//*
 *
 *	exit(errno); // what if max_errno > errno
 *
 */

void	error_message_no_exit(char *msg)
{
	g_exit_status = 1;
	ft_putstr_fd(PROMPT, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (errno)
		ft_putendl_fd(strerror(errno % 256), STDERR_FILENO);
}


char	*ft_strdup_protected(const char *src)
{
	char	*ptr;
	char	*des;
	int		len;

	len = slen((char *) src);
	des = malloc(sizeof(char) * (len + 1));
	if (!des)
		exit_error_alloc();
	ptr = des;
	while (*src)
		*des++ = *src++;
	*des = 0;
	return (ptr);
}

char	*ft_strndup_protected(const char *src, int n)
{
	char	*ptr;
	char	*des;
	int		size;
	int		i;

	size = slen((char *) src);
	if (size < n)
		des = malloc(sizeof(char) * (size + 1));
	else
		des = malloc(sizeof(char) * (n + 1));
	if (!des)
		exit_error_alloc();
	i = 0;
	ptr = des;
	while (*src && i < n)
	{
		*des++ = *src++;
		i++;
	}
	*des = 0;
	return (ptr);
}

char	*ft_strjoin_triple(char *s1, char *s2, char *s3)
{
	char	*temp;
	char	*r;

	temp = ft_strjoin_protected(s1, s2);
	if (!temp)
		exit_error_alloc();
	r = ft_strjoin_protected(temp, s3);
	if (!r)
		exit_error_alloc();
	free(temp);
	return (r);
}

// ft_strjoin_protected (with 2 helper function)

char		*_cat(char *, char *);
char		*_cpy(char *, char *);

char	*ft_strjoin_protected(char const *prefix, char const *suffix)
{
	int		size;
	char	*res;

	if (!prefix)
		return (0);
	if (!suffix)
		return ((char *) prefix);
	size = slen((char *) prefix) + slen((char *) suffix) + 1;
	res = (char *) malloc(sizeof(char) * size);
	if (!res)
		exit_error_alloc();
	_cpy(res, (char *) prefix);
	_cat(res, (char *) suffix);
	return (res);
}

char	*_cat(char *des, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (des[i])
		i++;
	while (src[j])
	{
		des[i + j] = src[j];
		j++;
	}
	des[i + j] = 0;
	return (des);
}

char	*_cpy(char *des, char *src)
{
	char	*tmp;

	tmp = des;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (des);
}
