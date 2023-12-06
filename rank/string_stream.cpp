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
#include <sstream>
#include <vector>

// DRIVE

std::vector<int> parseInts(std::string str);

int main()
{
    std::string         str;
    std::vector<int>    arr;

    std::cin >> str;
    arr = parseInts(str);
    for(int i = 0; i < (int) arr.size(); i++)
        std::cout << arr[i] << "\n";
    return 0;
}

//

std::vector<int> parseInts(std::string str)
{
    std::stringstream   s(str);
    std::vector<int>    arr;
    int                 temp;
    
    while (s >> temp)
    {
        arr.push_back(temp);
        if (s.peek() == ',') s.ignore();
    }
    return (arr);
}
