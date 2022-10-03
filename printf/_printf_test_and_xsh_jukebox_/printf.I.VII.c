#include "unistd.h"
#include "stdarg.h"

int	parse_format(va_list, char);
int	count_digit(int, int);
void	print_number_base(int, int);
int	print_string(char *s);
int	print_char(char);
int	print_format(const char *s, ...);

int	print_format(const char *s, ...)
{
	int	ret = 0, i = 0;

	va_list	ap;
	va_start(ap, s);

	while (s[i])
	{
		if (s[i] != 37)
		{
			ret += print_char(s[i]);
		}
		else
		{
			int temp = parse_format(ap, s[i++ + 1]);
			if (temp > -1)	ret += 1;
		}
		i++;
	}

	va_end(ap);

	return ret ;
}

int	parse_format(va_list ap, char c)
{
	int	temp, ret = 0;

	if (c == 's')
	{
		ret += print_string(va_arg(ap, char *));
	}
	if (c == 'd')
	{
		temp = va_arg(ap, int);
		if (temp == -2147483648)
		{
			ret += 11;
			write(1, "-2147483648", 11);
		}
		else
		{
			if (temp < 0)
			{
				write(1, "-" , 1);
				temp = -temp;
			}
			ret += count_digit(temp, 10);
			print_number_base(temp, 10);
		}
	}
	if (c == 'x')
	{
		temp = va_arg(ap, int);
		ret += count_digit(temp, 16);
		print_number_base(temp, 16);
	}
	if (c != 's' && c != 'd' && c != 'x')
	{
		ret = -1;
		write(1, &c, 1);
	}

	return ret ;
}

int	count_digit(int num, int base)
{
	int	ret = 1;
	while (num >= base && ++ret)
	{
		num = num / base ;
	}
	return ret ;
}

void	print_number_base(int num, int base)
{
	char	*base_string = "0123456789abcdef";
	if (num >= base)
	{
		print_number_base((num / base), base);
	}
	write(1, &base_string[num % base], 1);
}

int	print_string(char *s)
{
	int	i;
	if (!s)
	{
		i = 6;
		write(1, "(null)", i);
		return i ;
	}
	i = -1;
	while (s[++i])
	{
		write(1, &s[i], 1);
	}
	return i ;
}

int	print_char(char c)
{
	write(1, &c, 1);
	return 1 ; 
}

#include "stdio.h"
#define ss printf("--\n");
#define re(n) printf("\n(return value: %i)\n--\n", n);

int	main()
{
	ss;
	int n1 = print_format("%s\n%d\n%x\n", "icelandic folklore", 1024, 42);
	re(n1);
	int n2 = print_format("%s\n%d\n%x\n", "quantum mechanics", 2147483647, 255);
	re(n2);
	int n3 = print_format("%s\n%d\n%x\n", "second\tsailing", -2147483648, 3054);
	re(n3);
	int n4 = print_format("%s\n%d\n%x\n", "love\vfor\vsale", -10, 12648430);
	re(n4);
	//	stress test
	printf("\n:: Stress test ::\n");
	int t1 = print_format("%s\n");
	re(t1);
}
