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
//#include "stack" // stack push: to the top
#include "queue" // queue push: to the end

using   namespace std;

int     main(void)
{
        queue<int>  Q;
        string      s;
        int         n, m, x, y, i;

        cin >> n >> m;

        vector<vector<int>> E(n);
        vector<int>         parent(n, 0);
        vector<int>         seen(n, false);
        vector<int>         path;

        seen[0] = true;
        Q.push(0);

        i = 0;
        while (i++ < m)
        {
            cin >> x >> y;
            x -= 1;
            y -= 1;
            E[x].push_back(y);
            E[y].push_back(x);
        }

        while (!Q.empty())
        {
            x = Q.front();
            Q.pop();
            if (x == n - 1)
            {
                path.push_back(x);
                while (parent[x])
                {
                    x = parent[x];
                    path.push_back(x);
                }
                path.push_back(0);
                cout << path.size() << endl;
                i = (int) path.size();
                while (--i > -1)    cout << path[i] + 1 << ' ';
                cout << endl;
                return (0);
            }
            i = -1;
            while (++i < (int) E[x].size())
            {
                if (seen[E[x][i]])  continue;
                seen[E[x][i]] = true;
                parent[E[x][i]] = x;
                Q.push(E[x][i]);
            }
        }
        cout << "IMPOSSIBLE" << endl;
        return (0);
}
