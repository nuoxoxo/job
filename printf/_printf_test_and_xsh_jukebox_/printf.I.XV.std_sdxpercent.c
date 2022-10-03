#include "unistd.h"
#include "stdlib.h"
#include "stdarg.h"

int	fmt(va_list, const char);
int	route_str(char *);

int	route_hex(unsigned int);
void	print_hex(unsigned int);
int	count_hex(unsigned int);

int	route_dec(int);
int	count_dec(int);
char	*stos(char *);
char	*itoa(int);
int	Len(char *);

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	len;
	int	i;

	va_start(ap, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 37)
		{
			len += 1;
			write(1, &s[i], 1);
		}
		else
		{
			len += fmt(ap, s[i + 1]);
			i += 1;
		}
		i ++;
	}
	return len ;
}

int	fmt(va_list ap, const char c)
{
	int	len;

	len = 0;
	if (c == 's')	len += route_str(va_arg(ap, char *));
	if (c == 'd')	len += route_dec(va_arg(ap, int));
	if (c == 'x')	len += route_hex(va_arg(ap, unsigned int));
	if (c == '%')
	{
		len += 1;
		write(1, "%", 1);
	}

	return len ;
}

///	'd'

int	route_dec(int n)
{
	char	*num;
	int	len;

	num = itoa(n);
	len = route_str(num);
	free(num);
	return len ;
}

char	*itoa(int num)
{
	char	*res;
	int	len;

	if (num == -2147483648)	return stos("-2147483648");
	if (!num)		return stos("0");
	len = count_dec(num);
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (num < 0)
	{
		num = -num;
		res[0] = '-';
	}
	res[len --] = 0; // seal it
	while (num)
	{
		res[len --] = num % 10 + '0';
		num /= 10;
	}
	return res ;
}

char	*stos(char *S)
{
	char	*D;
	char	*head;
	int	len;

	len = Len(S);
	D = (char *) malloc(sizeof(char) * (len + 1));
	head = D;
	while (*S)	*D++ = *S++;
	*D = 0;
	return head ;
}

int	count_dec(int num)
{
	int	i;

	i = 0;
	if (num < 0)	num *= -1, i += 1;
	while (num)	num /= 10, i += 1;

	return i ;
}

int	Len(char *s)
{
	int	i;

	if (!s)	return 0 ;
	i = 0;
	while (s[i])	i++ ;
	return i ;
}

///	'x'

int	route_hex(unsigned int num)
{
	print_hex(num);
	return count_hex(num);
}

void	print_hex(unsigned int num)
{
	char	baseline[] = "0123456789abcdef";

	if (num >= 16)	print_hex(num / 16);
	write(1, &baseline[num % 16], 1);
}

int	count_hex(unsigned int num)
{
	int	len;

	len = 1;
	while (num >= 16 && ++len)	num /= 16;
	return len ;
}

///	's'

int	route_str(char *s)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		return 6 ;
	}
	i = -1;
	while (s[++i])	write(1, &s[i], 1);

	return i ;
}
