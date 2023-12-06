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

#include <iostream>

int     main(void) 
{
        int     edge, core, side, val, i, j;
        int     n;

        std::cin >> n;
        side = 2 * n - 1; 
        i = -1;
        while (++i < side)
        {
            core = i < n ? n - i : i - n + 2;
            edge = i < n ? i + 1 : side - i;
            j = 0;
            val = n;
            while (++j < edge)  std::cout << val-- << " ";
            j = 2 * core;
            val = core;
            while (--j > 0)     std::cout << val << " ";
            j = 0;
            val = core + 1;
            while (++j < edge)  std::cout << val++ << " ";
            std::cout << std::endl;
        } 

        return (0);
}
