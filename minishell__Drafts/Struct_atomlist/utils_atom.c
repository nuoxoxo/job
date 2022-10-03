#include "Atomlist.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
	}
	if (!c)
		return ((char *) & s[i]);
	return (0);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		d;

	if (!n)
		return (n);
	i = 0;
	while (str1[i] && str2[i] && \
		(unsigned char) str1[i] == (unsigned char) str2[i])
	{
		if (i == n - 1)
			return (0);
		i++;
	}
	d = (unsigned char) str1[i] - (unsigned char) str2[i];
	if (!d)
		return (d);
	if (d > 0)
		return (1);
	else
		return (-1);
}
