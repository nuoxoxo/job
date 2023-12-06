#include "iostream"
#include "sstream"
#include "vector"

using   namespace std;
using   vc = vector<char>;
using   vvc = vector<vector<char>>;

void    dfs(vvc& G, int x, int y)
{
        int C = G[0].size();
        int R = G.size();
        if (x < 0 || x >= R || y < 0 || y >= C) return ;
        if (G[x][y] == '#') return ;
        if (G[x][y] == '.') G[x][y] = '#'; // FILL
        dfs(G, x + 1, y);
        dfs(G, x - 1, y);
        dfs(G, x, y + 1);
        dfs(G, x, y - 1);
}

int     main(void)
{
        string  s;
        char    c;
        int     R, C, i, j, T = 0;
        vvc     G;

        cin >> R >> C;
        while (cin >> s)
        {
            stringstream    ss(s);
            vc              temp;

            while (ss >> c) temp.push_back(c);
            G.push_back(temp);
        }
        i = -1;
        while (++i < R)
        {
            j = -1;
            while (++j < C)
            {
                if (G[i][j] == '.')
                {
                    T++;
                    dfs(G, i, j);
                }
            }
        }
        cout << T << endl;

        return (0);
}
