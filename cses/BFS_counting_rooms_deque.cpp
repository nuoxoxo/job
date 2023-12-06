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
#include <deque>
#include <vector>
#include <tuple> // tie

using   namespace std;

void    DFS(vector<vector<char>>&, int, int, int, int);

int     main(void)
{
        deque<pair<int, int>>   Q;
        vector<int>             dr = {-1, 0, 1,  0};
        vector<int>             dc = { 0, 1, 0, -1};
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
            while (++j < C) DOTS[i][j] = (s[j] == '.');
        }

        i = -1;
        count = 0;
        while (++i < R)
        {
            j = -1;
            while (++j < C)
            {
                //deque<pair<int, int>>   Q;    // could be outside or here

                if (!DOTS[i][j] || SEEN[i][j])  continue ;
                count ++;
                Q.push_back({ i, j });
                while (!Q.empty())
                {
                    int     r, c, d;

                    tie(r, c) = Q.front();
                    Q.pop_front() ;
                    if (r >= R || r < 0 || c >= C || c < 0) continue;
                    if (!DOTS[r][c] || SEEN[r][c])  continue;
                    SEEN[r][c] = true;
                    d = -1;
                    while (++d < 4) Q.push_back({r + dr[d], c + dc[d]});
                }
            }
        }
        cout << count << endl;

        return (0);
}
