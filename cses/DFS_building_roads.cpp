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

#include "iostream"
#include "vector"

using   namespace std;
 
void    DFS(int, vector<bool>&, vector<vector<int>>&); 
//      long debugging came down to the above line, added the 2nd & 
 
int     main(void)
{
        int                 a, b, n, m, i;
        vector<int>         res;
 
        cin >> n >> m;
 
        vector<vector<int>> E(n);
        vector<bool>        G(n);

        i = -1;
        while (++i < m && cin >> a >> b)
        {
            a -- ;
            b -- ;
            E[a].push_back(b);
            E[b].push_back(a);
        } 
        i = -1;
        while (++i < n)
        {
            if (!G[i])
            {
                res.push_back(i);
                DFS(i, G, E);
            }
        }
        cout << res.size() - 1 << endl;
        i = 0;
        while (++i < (int) res.size())
        {
            cout << res[i - 1] + 1 << ' ' << res[i] + 1 << endl;
        }

        return (0);
}

void    DFS(int x, vector<bool>& G, vector<vector<int>>& E)
{
        int i;

        G[x] = true;
        i = -1;
        while (++i < (int) E[x].size())
        {
            if (!G[E[x][i]])  DFS(E[x][i], G, E);
        }
}
