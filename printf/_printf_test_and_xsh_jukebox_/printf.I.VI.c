/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

#include "stdarg.h"
#include "unistd.h"

int	PF(const char *s, ...);
int	FM(va_list, char); // formatter
int	DC(int, int);	// count digits for printf's returm value
void	PB(int, int);
int	PS(char *);
int	PC(char);

int	PF(const char *s, ...)
{
	va_list	ap;
	int	ret; // num of chars printed
	int	i;

	va_start(ap, s);
	ret = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != 37)	ret += PC(s[i]);
		else		ret += FM(ap, s[i + 1]), i ++; // format parser
		i ++;
	}
	va_end(ap);

	return ret ;
}

int	FM(va_list ap, char c)
{
	int	temp;
	int	ret;

	ret = 0;
	if (c == 's')
		ret += PS(va_arg(ap, char *));// va arg is a single arg
	if (c == 'd')
	{
		temp = va_arg(ap, int);
		if (temp == -2147483648)
		{
			ret += 11;
			write(1, "-2148473648", 11);
		}
		else
		{
			if (temp < 0)
			{
				write(1, "-", 1);
				temp = -temp;
			}
			ret += DC(temp, 10);
			PB(temp, 10);
		}
	}
	if (c == 'x')
	{
		temp = va_arg(ap, int);
		ret += DC(temp, 16);
		PB(temp, 16);
	}

	return ret ;
}

int	DC(int n, int base) // digit count, we need a helper fn for putnum
{
	int	ret;

	ret = 1;
	while (n >= base && ++ret)	n /= base ;
	return ret ;
}

void	PB(int n, int base)		// new function, remember it
{
	char	*B = "0123456789abcdef";
	if (n >= base)	PB((n / base), base);
	write(1, &B[n % base], 1);	// base case
}

int	PS(char *s)
{
	int	i;

	if (!s)
	{
		i = 6;
		write(1, "(null)", i);
		return i ;
	}
	i = -1;
	while (s[++i])	write(1, &s[i], 1);
	return i ;
}

int	PC(char c)
{
	write(1, &c, 1);

	return 1 ;
}

//	DRIVE

#include "stdio.h"
#define	ss	printf("\n--\n\n")
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
