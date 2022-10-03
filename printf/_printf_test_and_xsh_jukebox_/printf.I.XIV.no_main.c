/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

#include "unistd.h"
#include "stdarg.h"
#include "stdlib.h"

int	fmt(va_list, const char c);	// Formatter
int	print_str(char *);		// s

int	route_hex(unsigned int);	// x
int	count_hex(unsigned int);
void	print_hex(unsigned int);

int	route_dec(int);			// d
char	*do_it_itoa(int);
char	*scopy_dec(char *src);
int	count_dec(long n);

int	len(char *s);

int	ft_printf(const char *s, ...)
{
	int		len, i;
	va_list		ap;

	va_start(ap, s);
	i = len = 0;
	while (s[i])
	{
		if (s[i] == 37)
		{
			len += fmt(ap, s[i + 1]);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			len++;
		}
		i++;
	}
	va_end(ap);
	return len ;
}

int	fmt(va_list ap, const char c)
{
	int	len;

	len = 0;
	if (c == '%')
	{
		write(1, "%", 1);
		len ++;
	}
	if (c == 's')
	{
		len += print_str(va_arg(ap, char *));
	}
	if (c == 'd')
	{
		len += route_dec(va_arg(ap, int));
	}
	if (c == 'x')
	{
		len += route_hex(va_arg(ap, unsigned int));
	}
	return len ;
}

///	ROUTE STR

int	print_str(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return 6 ;
	}
	i = -1;
	while (s[++i])
	{
		write(1, &s[i], 1);
	}
	return i ;
}

///	ROUTE HEX

int	route_hex(unsigned int num)
{
	print_hex(num);
	return count_hex(num) ;
	
}

void	print_hex(unsigned int num)
{
	char	base_string[] = "0123456789abcdef";

	if (num >= 16)	print_hex(num / 16);
	write(1, &base_string[num % 16], 1);
}

int	count_hex(unsigned int num)
{
	int	len = 1;

	while (num >= 16 && ++len)	num /= 16;
	return len ;
}

///	ROUTE DEC . ITOA

int	route_dec(int n)
{
	char	*num;

	num = do_it_itoa(n);
	free(num);
	return (print_str(num));
}

char	*do_it_itoa(int n)
{
	char	*res;
	long	num;
	int	len;

	num = n;
	if (num == -2147483648)
		return (scopy_dec("-2147483648"));
	len = count_dec(num);
	if (!len)
		return (scopy_dec("0"));
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

char	*scopy_dec(char *src)
{
	char	*ptr;
	char	*des;
	int		size;

	size = len((char *) src);
	des = malloc(sizeof(char) * (size + 1));
	if (!des)
		return (NULL);
	ptr = des;
	while (*src)
		*des++ = *src++;
	*des = 0;
	return (ptr);
}

int	count_dec(long n)
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

int	len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
