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
    int     n;

    std::string  num[13] = {"zero", "one", "two", \
        "three", "four", "five", "six", "seven", "eight", \
        "nine", "ten", "Greater than 10", "Less than 0"};
    std::cin >> n;
    if (n > 10)     std::cout << num[11];
    else if (n < 0) std::cout << num[12];
    else            std::cout << num[n];
    std::cout << std::endl;

    return 0;
}
