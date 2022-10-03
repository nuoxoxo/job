#include "stdarg.h"
#include "stdlib.h"
#include "unistd.h"



int	fmt(va_list, const char);
int	route_str(char *);
int	route_hex(unsigned int);
int	route_dec(int);
int	count_dec(int);
int	count_hex(unsigned int);
void	print_hex(unsigned int);
char	*itoa(int);
char	*stos(char *);
int	Len(char *);



int	ft_printf(const char *s, ...)
{
	int	res = 0, i = -1;
	va_list	ap;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == 37)	res += fmt(ap, s[i + 1]), i++;
		else		res += 1, write(1, &s[i], 1);
	}
	return res ;
}


/*
#include "stdio.h"
#define ss printf("\n");
int	main(){
	int	n1 = ft_printf(" %s ", "hello, world!");
	ss;
	printf("%i", n1);
	ss;
	int	n2 = ft_printf(" %x ", 42);
	ss;
	printf("%i", n2);
	ss;

	int	nx = ft_printf(" %x ", 0);
	ss;
	printf("%i", nx);
	ss;

	int	n3 = ft_printf(" %d ", -2147483648);
	ss;
	printf("%i", n3);
	ss;
}
*/



int	fmt(va_list ap, const char c)
{
	int	res = 0;
	if (c == 's')	res += route_str(va_arg(ap, char *));
	if (c == 'd')	res += route_dec(va_arg(ap, int));
	if (c == 'x')	res += route_hex(va_arg(ap, unsigned int));
	if (c == '%')	res += 1, write(1, "%", 1);
	return res ;
}




int	route_str(char *s)
{
	int	i = 6;
	if (!s)
	{
		write(1,"(null)",i);
		return i ;
	}
	i = -1;
	while (s[++i])	write(1, &s[i], 1);
	return i ;
}



int	route_hex(unsigned int num)
{
	int	len = count_hex(num);
	print_hex(num);
	return len ;
}



int	route_dec(int n)
{
	char	*num = itoa(n);
	int	len = route_str(num);
	//printf("sss %s\n", num);
	free(num);
	return len ;
}



int	count_dec(int num)
{
	int	res = 1;
	if (num < 0)	num *= -1, res++;
	while (num>=10)	num /= 10, res++;
	return res ;
}



int	count_hex(unsigned int num)
{
	int	res = 1;
	while (num >= 16)	num /= 16, res++;
	return res ;
}



void	print_hex(unsigned int num)
{
	char	*baseline = "0123456789abcdef";
	if (num >= 16)	print_hex(num / 16); // XXX used `while` again
	write(1, &baseline[num % 16], 1);
}



char	*itoa(int num)
{
	if (num == -2147483648)	return stos("-2147483648");
	if (!num)		return stos("0");
	int	len = count_dec(num);
	char	*res = (char *) malloc(sizeof(char) * (len + 1));
	res[len--] = 0;
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	while (num)	res[len--] = num % 10 + '0', num /= 10;
	return res ;
}



char	*stos(char *src)
{
	char	*head, *des;
	int	len = Len(src);
	des = (char *) malloc(sizeof(char) * (len + 1));
	head = des;
	while (*src)	*des ++ = *src ++;
	//des[len] = 0;
	*des = 0;
	//return des ; // XXX
	return head ;
}



int	Len(char *s)
{
	int	i = 0;
	while (s[i])	i++;
	return i ;
}
