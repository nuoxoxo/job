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

#include <stdio.h>

int     main(void) 
{
        int     side, val, i, j;
        int     n;

        scanf("%d", &n); 
        side = 2 * n - 1;
        i = -1;
        while (++i < side)
        {
            if (i < n)
            {
                j = 0;
                val = n;
                while (++j < i + 1) printf("%i ", val--);
                j = 2 * (n - i);
                val = n - i;
                while (--j > 0) printf("%i ", val);
                j = 0;
                val = n - i + 1;
                while (++j < i + 1) printf("%i ", val++);
            }
            else
            {
                j = 0;
                val = n;
                while (++j < side - i) printf("%i ", val--);
                j = 2 * (i - n + 2);
                val = i - n + 2;
                while(--j > 0)  printf("%i ", val);
                j = 0;
                val = i - n + 3;
                while (++j < side - i) printf("%i ", val++);
            }
            printf("\n");
        } 

        return (0);
}
