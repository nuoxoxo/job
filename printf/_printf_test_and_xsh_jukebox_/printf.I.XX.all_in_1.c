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

#include "stdlib.h"

#include "unistd.h"

int route_str(char * );
int route_dec(int);
int count_dec(int);
int coutn_hex(unsigned int);
int route_hex(unsigned int, char * );
void print_hex(unsigned int, char * );
char * itoa(int);
char * stos(char * );
int Len(char * );
int fmt(va_list ap,
        const char c);
int route_uin(unsigned int); // new
int count_uin(unsigned int);
char * uitoa(unsigned int);

int route_chr(int); /// FIXME

//int	route_ptr(void *); /// FIXME
int route_ptr(uintptr_t);
int count_ptr(uintptr_t);
void print_ptr(uintptr_t); /// FIXME


//	DRIVE

#include "stdio.h"
#define ss printf("--\n");
int	ft_printf(const char *,  ...  );
int	main()
{
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
	int n4 = ft_printf(" %p ", 0);
	printf("\n%i\n", n4);
	ss;
	int n5 = ft_printf(" %p ", 123);
	printf("\n%i\n", n5);
}


//	B0DY

int fmt(va_list ap,
        const char c) {
        int len;

        if (c == 'x')
                len = route_hex(va_arg(ap, unsigned int), "0123456789abcdef");
        if (c == 'X')
                len = route_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
        if (c == 'u')
                len = route_uin(va_arg(ap, unsigned int)); // new
        if (c == 's')
                len = route_str(va_arg(ap, char * ));
        if (c == 'd' || c == 'i')
                len = route_dec(va_arg(ap, int));
        if (c == 'c')
                len = route_chr(va_arg(ap, int));
        if (c == '%')
                len = write(1, & c, 1);

        if (c == 'p')
                len = route_ptr(va_arg(ap, uintptr_t));

        return len;
}

int ft_printf(const char * s, ...) {
        int res = 0;
        int i = -1;
        va_list ap;
        va_start(ap, s);
        while (s[++i]) {
                if (s[i] == 37) res += fmt(ap, s[i + 1]), i += 1;
                else res += 1, write(1, & s[i], 1);
        }
        return res;
}

int route_ptr(uintptr_t num) {
        write(1, "0x", 2);
        if (!num) {
                write(1, "0", 1);
        } else {
                print_ptr(num);
        }

        return (count_ptr(num));
}

void print_ptr(uintptr_t num) {
        char * baseline = "0123456789abcdef";

        if (num >= 16)
                print_ptr(num / 16);
        write(1, & baseline[num % 16], 1);
}

/* copied here just to read
void print_hex(unsigned int num, char *baseline)
{
    if (num >= 16)
	    print_hex(num / 16, baseline);
    write(1, &baseline[num % 16], 1);
}
*/

int count_ptr(uintptr_t x) {
        int i = 3;

        if (!x) return i;
        while (x >= 16) x /= 16, i++;

        return i;
}

int route_chr(int c) {
        return write(1, & c, 1);
}



//  help

void print_hex(unsigned int num, char * baseline) {
        if (num >= 16)
                print_hex(num / 16, baseline);
        write(1, & baseline[num % 16], 1);
}

int count_hex(unsigned int x) {
        int i = 1;
        while (x >= 16) x /= 16, i++;
        return i;
}

int route_hex(unsigned int num, char * baseline) {
        print_hex(num, baseline);
        return count_hex(num);
}

char * itoa(int num) {
        if (num == -2147483648) return stos("-2147483648");
        if (num == 0) return stos("0");
        int len = count_dec(num);
        char * res = (char * ) malloc(sizeof(int) * (len + 1));
        if (num < 0) num *= -1, res[0] = '-';
        res[len--] = 0;
        while (num) res[len--] = num % 10 + '0', num /= 10;
        return res;
}

char * stos(char * src) {
        char * Head, * des;
        int len = Len(src);
        des = (char * ) malloc(sizeof(char) * (len + 1));
        Head = des;
        while ( * src) * des++ = * src++;
        * des = 0;
        return Head;
}

int count_dec(int num) {
        int i = 1;
        if (num < 0) num *= -1, i++;
        while (num >= 10) num /= 10, i++;
        return i;
}

int route_dec(int n) {
        char * num = itoa(n);
        int len = route_str(num);
        free(num);
        return len;
}

int route_uin(unsigned int n) {
        char * num = uitoa(n);
        int len = route_str(num);
        free(num);
        return len;
}

int count_uin(unsigned int num) {
        int i = 1;
        while (num >= 10) num /= 10, i++;
        return i;
}

char * uitoa(unsigned int num) {
        if (num == 0) return stos("0");
        int len = count_uin(num);
        char * res = (char * ) malloc(sizeof(int) * (len + 1));
        res[len--] = 0;
        while (num) res[len--] = num % 10 + '0', num /= 10;
        return res;
}

int route_str(char * s) {
        int i = 6;
        if (!s) {
                write(1, "(null)", i);
                return i;
        }
        i = -1;
        while (s[++i]) write(1, & s[i], 1);
        return i;
}

int Len(char * s) {
        int i = 0;
        while (s[i]) i++;
        return i;
}
