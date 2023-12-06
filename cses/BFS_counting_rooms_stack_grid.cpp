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
#include <vector>
#include <stack>
#include <tuple>    // tie
#include <sstream>  // actual grid

using   namespace std;

void    DFS(vector<vector<char>>&, int, int, int, int);

int     main(void)
{
        vector<vector<char>>    G;
        stack<pair<int, int>>   S;
        string                  s;
	char			c; // scope pb: cf after line 60
        int                     x, y, R, C, count;

        cin >> R >> C;

        vector<vector<int>>     seen(R, vector<int>(C, false));

        x = -1;
        while (++x < R && cin >> s)
        {
	    stringstream    ss(s);
	    vector<char>    temp;

            y = -1;
            while (++y < C)
            {
                ss >> c;
                temp.push_back(c);
            }
            G.push_back(temp);
        }

        x = -1;
        count = 0;
        while (++x < R)
        {
            y = -1;
            while (++y < C)
            {
                if (G[x][y] != '.' || seen[x][y])
                    continue ;
                S.push( { x, y } );
                count ++;
                while (!S.empty())
                {
                    int r, c;

                    tie(r, c) = S.top();
                    S.pop();
                    if (r >= R || r < 0 || c >= C || c < 0) continue;
                    if (G[r][c] != '.' || seen[r][c])       continue;
                    seen[r][c] = true;
                    S.push( {r - 1, c} );
                    S.push( {r + 1, c} );
                    S.push( {r, c + 1} );
                    S.push( {r, c - 1} );
                }
            }
        }
        cout << count << endl;

        return (0);
}
