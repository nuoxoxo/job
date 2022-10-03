#include "Envlist.h"

int	len(char *s); // static dependency for s(n)dup

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	err_alloc(void)
{
	ft_putendl_fd("cannot allocate memory. ", STDERR_FILENO); //  never reach
	g_exit_status = 12;
	exit(g_exit_status);
}

char	*sdup2(const char *src)
{
	char	*ptr;
	char	*des;
	int		size;

	size = len((char *) src);
	des = malloc(sizeof(char) * (size + 1));
	if (!des)
		err_alloc();
	ptr = des;
	while (*src)
		*des++ = *src++;
	*des = 0;
	return (ptr);
}

char	*sndup2(const char *src, int n)
{
	char	*ptr;
	char	*des;
	int		size;
	int		i;

	size = len((char *) src);
	if (size < n)
		des = malloc(sizeof(char) * (size + 1));
	else
		des = malloc(sizeof(char) * (n + 1));
	if (!des)
		err_alloc();
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && ++i)
		;
	return (s1[i] - s2[i]);
}

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ++i)
		;
	return (i);
}
