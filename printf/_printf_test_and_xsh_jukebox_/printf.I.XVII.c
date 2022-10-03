#include "stdarg.h"
#include "stdlib.h"
#include "unistd.h"

int route_str(char *);
int route_dec(int);
int count_dec(int);
int coutn_hex(unsigned int);
int route_hex(unsigned int);
void    print_hex(unsigned int);
char    *itoa(int);
char    *stos(char *);
int Len(char *);
int fmt(va_list ap, const char c);

int ft_printf(const char *s, ... )
{
    int res = 0;
    int i = -1;
    va_list ap;
    va_start(ap, s);
    while (s[++i])
    {
        if (s[i] == 37) res += fmt(ap, s[i + 1]), i += 1;
        else            res += 1, write(1, &s[i], 1);
    }
    return res ;
}


/*
//  DRIVE
#include "stdio.h"
#define ss printf("--\n");
int main(){
    int n1 = ft_printf(" %s ", "hello, world!");
    printf("\n%i\n", n1);
    ss;
    int n2 = ft_printf(" %d ", -2147483648);
    printf("\n%i\n", n2);
    ss;
    int nd = ft_printf(" %d ", -42);
    printf("\n%i\n", nd);
    ss;
    int n3 = ft_printf(" %x ", 42);
    printf("\n%i\n", n3);
    ss;
}
*/


//  help

void print_hex(unsigned int num)
{
    char *baseline = "0123456789abcdef";
    if (num >= 16)  print_hex(num / 16);
    write(1, &baseline[num % 16], 1);
}

int count_hex(unsigned int x)
{
    int i = 1;
    while (x >= 16) x /= 16, i++;
    return i ;
}

int route_hex(unsigned int num)
{
    print_hex(num);
    return count_hex(num) ;
}

char    *itoa(int num)
{
    if (num == -2147483648) return stos("-2147483648");
    if (num == 0)           return stos("0");
    int len = count_dec(num);
    char    *res = (char *) malloc(sizeof(int) * (len + 1));
    if (num < 0)    num *= -1, res[0] = '-';
    res[len--] = 0;
    while (num) res[len--] = num % 10 + '0', num /= 10;
    return res ;
}

char    *stos(char *src)
{
    char *Head, *des;
    int len = Len(src);
    des = (char *) malloc(sizeof(char) * (len + 1));
    Head = des ;
    while (*src)    *des ++ = *src ++ ;
    *des = 0;
    return Head ;
}

int count_dec(int num)
{
    int i = 1;
    if (num < 0)        num *= -1, i++;
    while (num >= 10)   num /= 10, i++;
    return i ;
}

int route_dec(int n)
{
    char    *num = itoa(n);
    int len = route_str( num );
    free(num);
    return len ;
}

int route_str(char *s)
{
    int i = 6;
    if (!s)
    {
        write(1, "(null)", i);
        return i ;
    }
    i = -1;
    while (s[++i])  write(1, &s[i], 1);
    return i ;
}

int Len(char *s)
{
    int i = 0;
    while (s[i])    i++;
    return i ;
}

int fmt(va_list ap, const char c)
{
    int len = 0;
    if (c == 's')   len += route_str(va_arg(ap, char *));
    if (c == 'd')   len += route_dec(va_arg(ap, int));
    if (c == 'x')   len += route_hex(va_arg(ap, unsigned int));
    if (c == '%')   len += 1, write(1, "%", 1);
    return len ;
}
