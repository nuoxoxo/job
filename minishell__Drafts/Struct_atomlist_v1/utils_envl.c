#include "Envlist.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	exit_error_alloc(void)
{
	ft_putendl_fd("cannot allocate memory. ", 2); //  never reach
	exit(12);
	// 12 - ENOMEM - Out of memory
}

char	*sdup2(const char *src)
{
	char	*ptr;
	char	*des;
	int		size;

	size = slen((char *) src);
	des = malloc(sizeof(char) * (size + 1));
	if (!des)
		exit_error_alloc();
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

int	ft_strcmp(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && ++i)
		;
	return (s1[i] - s2[i]);
}

int	slen(char *s)
{
	int	i;

	i = 0;
	while (s[i] && ++i)
		;
	return (i);
}

//	NEW for this sandbox

int	ft_isdigit(int c)
{
	if (c > '9' || c < '0')
		return (0);
	return (1);
}

int	ft_isalpha(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

char	*strdup_itoa(const char *src);
int		count_digit(long n);
int		len_itoa(char *s);

char	*ft_itoa(int n)
{
	char	*res;
	long	num;
	int		len;

	num = n;
	if (num == -2147483648)
		return (strdup_itoa("-2147483648"));
	len = count_digit(num);
	if (!len)
		return (strdup_itoa("0"));
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	res[len--] = 0;
	while (n)
	{
		res[len--] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}

int	count_digit(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i += 1;
	}
	while (n)
	{
		n /= 10;
		i += 1;
	}
	return (i);
}

char	*strdup_itoa(const char *src)
{
	char	*ptr;
	char	*des;
	int		size;

	size = len_itoa((char *) src);
	des = malloc(sizeof(char) * (size + 1));
	if (!des)
		return (NULL);
	ptr = des;
	while (*src)
		*des++ = *src++;
	*des = 0;
	return (ptr);
}

int	len_itoa(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*cat(char *, char *);
char		*cpy(char *, char *);

char	*ft_strjoin2(char const *prefix, char const *suffix)
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
	cpy(res, (char *) prefix);
	cat(res, (char *) suffix);
	return (res);
}

char	*cat(char *des, char *src)
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

char	*cpy(char *des, char *src)
{
	char	*tmp;

	tmp = des;
	while (*src)
		*tmp++ = *src++;
	*tmp = 0;
	return (des);
}
