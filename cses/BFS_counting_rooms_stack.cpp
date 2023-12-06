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
#include <tuple>

using   namespace std;

void    DFS(vector<vector<char>>&, int, int, int, int);

int     main(void)
{
        stack<pair<int, int>>   S;
        string                  s;
        int                     i, j, R, C, count;

        cin >> R >> C;

        vector<vector<int>> DOTS(R, vector<int>(C, false));
        vector<vector<int>> SEEN(R, vector<int>(C, false));

        i = -1;
        while (++i < R) // while(cin>>s) asserts input provides exactly R rows
        {
            cin >> s;
            j = -1;
            while (++ j < C) if ( s[j] == '.' ) DOTS[i][j] = true;
        }

        i = -1;
        count = 0;
        while (++i < R)
        {
            j = -1;
            while (++j < C)
            {
                if (!DOTS[i][j] || SEEN[i][j])  continue ;
                count ++;
                S.push({ i, j });
                while (!S.empty())
                {
                    int r, c;

                    tie(r, c) = S.top();
                    S.pop() ;
                    if (r >= R || r < 0 || c >= C || c < 0) continue;
                    if (!DOTS[r][c] || SEEN[r][c])          continue;
                    SEEN[r][c] = true;
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
