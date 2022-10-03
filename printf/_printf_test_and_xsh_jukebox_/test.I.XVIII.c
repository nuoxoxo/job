int ft_printf(const char *, ... );
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
