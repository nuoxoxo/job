#include "stdlib.h"
#include "stdarg.h"
#include "unistd.h"

int Len(char *); //
char *itoa(int); //
char *stos(char *); //
int fmt(va_list, const char); //
int route_str(char *); //
int route_hex(unsigned int);
int route_dec(int); //
int count_dec(int); //
int count_hex(unsigned int);
void print_hex(unsigned int);

int ft_printf(const char *s, ... )
{
    int res = 0;
    int i = -1;
    va_list ap;
    va_start(ap, s);
    while (s[++i])
    {
        if (s[i] == 37) res += fmt(ap, s[i + 1]), i++;
        else            res += 1, write(1, &s[i], 1);
    }
    return res ;
}

/*
//  DRIVE
#include "stdio.h"
#define ss printf("--\n");
int main()
{
    ss;
    int n1 = ft_printf(" %s ", "hello, world!");
    printf("\n%i\n",n1);
    ss;
    int n2 = ft_printf(" %d ", -2147483648);
    printf("\n%i\n",n2);
    ss;
    int n3 = ft_printf(" %x ", 42);
    printf("\n%i\n",n3);
    ss;
    int n4 = ft_printf(" %d ", -42);
    printf("\n%i\n",n4);
}
*/

int fmt(va_list ap, const char c)
{
    int res ;
    if (c == 's') res = route_str(va_arg(ap, char *));
    if (c == 'd') res = route_dec(va_arg(ap, int));
    if (c == 'x') res = route_hex(va_arg(ap, unsigned int));
    if (c == '%') res = 1, write(1, "%", 1);
    return res ;
}

int route_hex(unsigned int x)
{
    print_hex(x);
    return count_hex(x) ;
}

void print_hex(unsigned int num)
{
    char *baseline = "0123456789abcdef";
    if (num >= 16) print_hex(num / 16);
    write(1, &baseline[ num % 16 ], 1);
}

int count_hex(unsigned int num)
{
    int i = 1;
    while (num >= 16)   i++, num /= 16;
    return i ;
}

int route_dec(int n)
{
    char *num = itoa(n);
    int len = route_str(num);
    free(num);
    return len ;
}

char *itoa(int num)
{
    if (num == -2147483648) return stos("-2147483648");
    if (!num)               return stos("0");
    int len = count_dec(num);
    char *res = malloc(len + 1);
    if (num < 0)    num *= -1, res[0] = '-';
    res[len--] = 0;
    while (num) res[len--] = num % 10 + '0', num /= 10;
    return res ;
}

int count_dec(int num)
{
    if (!num) return 0 ;
    int res = 1;
    if (num < 0)        res++, num *= -1;
    while (num >= 10)   res++, num /= 10;
    return res ;
}

char *stos(char *s)
{
    if (!s) return NULL ;
    int len = Len(s);
    char *d = malloc(len + 1), *p = d;
    while (*s) *d++ = *s++;
    *d = 0;
    return p ;
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
    if (!s) return 0 ;
    int i = 0;
    while (s[i])    i++ ;
    return i ;
}
