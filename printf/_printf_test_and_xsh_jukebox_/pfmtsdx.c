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

int	fmt(va_list, const char c);	// Formatter
int	print_str(char *);		// s
int	route_dec(int);			// d
int	count_dec(int);
void	print_dec(int);
int	route_hex(unsigned int);	// x
int	count_hex(unsigned int);
void	print_hex(unsigned int);
//	nothing for %

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

int	route_dec(int num)
{
	int	i = 0;

	if (num == -2147483648)
	{
		write(1, "-2147483648", 1);
		return 11 ;
	}
	if (num < 0)
	{
		i = 1;
		num *= -1;
	}
	print_dec(num);
	//printf("check: %i, %i\n", count_dec(num), i);
	return (count_dec(num) + i) ;
}

void	print_dec(int num)
{
	char	c;

	if (num < 0)
	{
		write(1, "-", 1);
		print_dec(num * -1);
	}
	else if (num < 10 && num > -1)
	{
		c = num + '0';
		write(1, &c, 1);
	}
	else
	{
		print_dec(num / 10);
		c = num % 10 + '0';
		write(1, &c, 1);
	}
}

int	count_dec(int num)
{
	int	len = 1;

	while (num >= 10 && ++len)	num /= 10;
	return len ;
}

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

//	DRIVE

#include "stdio.h"
#define ss printf("\n--\n");
#define re(n) printf("\n(return value: %i)\n--\n", n);

int	main()	// new tests
{
	char *s2 = "Mussum Ipsum, cacilds vidis litro abertis. \
		    Posuere libero varius. \
		    Nullam a nisl ut ante blandit hendrerit. \
		    Aenean sit amet nisi. Atirei o pau no gatis, \
		    per gatis num morreus.";

	ft_printf("%s", "");
	ss;
	ft_printf(" %s", "");
	ss;
	ft_printf("%s ", "");
	ss;
	ft_printf(" %s ", "");
	ss;
	ft_printf(" %s ", "-");
	ss;
	ft_printf(" %s %s ", "", "-");
	ss;
	ft_printf(" %s %s ", " - ", "");
	ss;
	ft_printf(" %s %s %s %s %s", " - ", "", "4", "", s2);
	ss;
	ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	ss;
	ft_printf(" NULL %s NULL ", NULL);
	ss;
}

/*
int	main()
{
	int	n1,n2,n3,n4;
	ss;
	n1 = PF("%s\n%d\n%x\n", "icelandic folklore", 1024, 42);
	printf("(Return value: %i)\n", n1);
	
	ss;
	n2 = PF("%s\n%d\n%x\n", "quantum mechanics", 2147483647, 255);
	printf("(Return value: %i)\n", n2);

	ss;
	n3 = PF("%s\n%d\n%x\n", "second\tsailing", -2147483648, 3054);
	printf("(Return value: %i)\n", n3);

	ss;
	n4 = PF("%s\n%d\n%x\n", "love\vfor\vsale", -10, 12648430);
	printf("(Return value: %i)\n", n4);
	ss;
}
*/

/*
int	main()
{
	ss;
	int 	n1 = P("%s\n%d\n%x\n", "icelandic folklore", 1024, 42);
	int	n11 = printf("%s\n%d\n%x\n", "icelandic folklore", 1024, 42);
	printf("%i %i\n", n1, n11);

	ss;
	int	n2 = P("%s\n%d\n%x\n", "quantum mechanics", 2147483647, 255);
	int	n22 = printf("%s\n%d\n%x\n", "quantum mechanics", 2147483647, 255);
	printf("%i %i\n", n2, n22);

	//ss;
	//int	n3 = P("%s\n%d\n%x\n", "second\tsailing", -2147483648, 3054);
	//int	n33 = printf("%s\n%d\n%x\n", "second\tsailing", -2147483648, 3054);
	//printf("%i %i\n", n3, n33);

	ss;
	int	n4 = P("%s\n%d\n%x\n", "love\vfor\vsale", -10, 12648430);
	int	n44 = printf("%s\n%d\n%x\n", "love\vfor\vsale", -10, 12648430);
	printf("%i %i\n", n4, n44);
	ss;

	ss;
	int	p1 = P("%");
	int	p11 = printf("%");
	int	p2 = P("% ");
	int	p22 = printf("% ");
	int	p3 = P("% % ");
	int	p33 = printf("% % ");
	int	p4 = P("%  ");
	int	p44 = printf("%  ");
	int	p5 = P("%  ");
	int	p55 = printf("%  ");
}
*/

/*
int	main()
{
	char *str = NULL;
	printf("\n\nTEST %%s\n\n");
	printf("\n___TEST %%s___\n");
	printf("No original - %d\n", ft_printf("|%s|\n", str));
	printf("Original - %d\n", printf("|%s|\n", str));

	printf("\n___TEST %%ss___\n");
	printf("No original - %d\n", ft_printf("|%ss|\n", str));
	printf("Original - %d\n", printf("|%ss|\n", str));

	printf("\n___TEST %%20s___\n");
	printf("No original - %d\n", ft_printf("|%20s|\n", str));
	printf("Original - %d\n", printf("|%20s|\n", str));

	printf("\n___TEST %%2s___\n");
	printf("No original - %d\n", ft_printf("|%2s|\n", str));
	printf("Original - %d\n", printf("|%2s|\n", str));

	printf("\n\nTEST %%d\n\n");
	int num = 0;
	printf("\n___TEST %%d___\n");
	printf("No original - %d\n", ft_printf("|%d|\n", num));
	printf("Original - %d\n", printf("|%d|\n", num));

	printf("\n___TEST %%dd___\n");
	printf("No original - %d\n", ft_printf("|%dd|\n", num));
	printf("Original - %d\n", printf("|%dd|\n", num));

	printf("\n___TEST %%20d___\n");
	printf("No original - %d\n", ft_printf("|%20d|\n", num));
	printf("Original - %d\n", printf("|%20d|\n", num));

	printf("\n___TEST %%2d___\n");
	printf("No original - %d\n", ft_printf("|%2d|\n", num));
	printf("Original - %d\n", printf("|%2d|\n", num));

	printf("\n\nTEST %%x\n\n");
	unsigned int un = 0;
	printf("\n___TEST %%x___\n");
	printf("No original - %d\n", ft_printf("|%x|\n", un));
	printf("Original - %d\n", printf("|%x|\n", un));

	printf("\n___TEST %%xx___\n");
	printf("No original - %d\n", ft_printf("|%xx|\n", un));
	printf("Original - %d\n", printf("|%xx|\n", un));

	printf("\n___TEST %%20x___\n");
	printf("No original - %d\n", ft_printf("|%20x|\n", un));
	printf("Original - %d\n", printf("|%20x|\n", un));

	printf("\n___TEST %%2x___\n");
	printf("No original - %d\n", ft_printf("|%2x|\n", un));
	printf("Original - %d\n", printf("|%2x|\n", un));
}
*/
