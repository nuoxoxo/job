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

#include "stdio.h"
#include "stdarg.h"
#include "string.h" // strlen

#define S printf("--\n")

void    print_ints(int size, ...)
{
        va_list ap;
        int     i, n;

        va_start(ap, size);
        i = -1;
        while (++i < size)
        {
            n = va_arg(ap, int);
            printf("%0.2d: %d\n", i + 1, n);
        }
        va_end(ap);
}

void    print_char(int size, ...)
{
        va_list ap;
        int     c;
        int     i;

        va_start(ap, size);
        i = -1;
        while (++i < size)
        {
            c = va_arg(ap, int);
            printf("%0.2d: %c\n", i + 1, c);
        }
        va_end(ap);
}

void    print_strs(int size, ...)
{
        va_list ap;
        int     i;

        va_start(ap, size);
        i = -1;
        while (++i < size)
        {
            char *s = va_arg(ap, char *);
            printf("%0.2d: %s", i + 1, s);
            if (s[strlen(s) - 1] != 10) printf("\n");
        }
        va_end(ap);
}

//      types must be self promoting types
//      char short float NO
//      int, double, pointer YES

int     main()
{
        S;
        print_ints(4,32,64,512,1024);
        S;
        print_char(4,'a','b','x','y');
        S;
        print_strs(4,"xyz","abc","(new-\n","-line)");
        S;
}
