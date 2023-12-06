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
#include <vector>

int main()
{
    std::vector< std::vector<int> > grid;
    int n, q, k, i, j, temp;
    
    std::cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        std::vector<int>    arr;
        std::cin >> k;
        for (int j = 0; j < k; j++)
        {
            std::cin >> temp;
            arr.push_back(temp);
        }
        grid.push_back(arr);
    }
    for (int x = 0; x < q; x++)
    {
        std::cin >> i >> j;
        std::cout << grid[i][j] << std::endl;
    }
    return (0);
}
