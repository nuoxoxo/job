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

#include <iostream>
#include <sstream>
#include <vector>

using   namespace std;

void    DFS(vector<vector<char>>&, int, int, int, int);

int     main(void)
{
        vector<vector<char>>    grid;
        string                  s;
        char                    c;
        int                     i, j, row, col, count;

        cin >> row >> col;
        while (cin >> s)
        {
            vector<char>    temp;
            stringstream    ss(s);

            while (ss >> c) temp.push_back(c);
            grid.push_back(temp);
        }
        i = -1;
        count = 0;
        while (++i < row)
        {
            j = -1;
            while (++j < col)
            {
                if (grid[i][j] == '.')
                {
                    count ++ ;
                    DFS(grid, i, j, row, col);
                }
            }
        }
        cout << count << endl;

        return (0);
}

void    DFS(vector<vector<char>>& g, int x, int y, int r, int c)
{
        if (x < 0 || x >= r || y < 0 || y >= c) return ;
        if (g[x][y] == '#') return ;
        if (g[x][y] == '.') g[x][y] = '#';
        DFS(g, x + 1, y, r, c);
        DFS(g, x - 1, y, r, c);
        DFS(g, x, y + 1, r, c);
        DFS(g, x, y - 1, r, c);
}
