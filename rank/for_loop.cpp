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

int main()
{
    int a, b;
    std::string num[11] = {"even", "one", "two", "three", \
        "four", "five", "six", "seven", "eight", "nine", "odd"};
    
    std::cin >> a >> b; 
    for (int i = a; i <= b; i++)
    {
        if (i < 10) std::cout << num[i] << std::endl;
        else
        {
            if (i % 2)  std::cout << num[10] << std::endl;
            else        std::cout << num[0] << std::endl;
        }
    }
    return 0;
}
