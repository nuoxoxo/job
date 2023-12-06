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
#include "tuple" // tie
#include "algorithm" // reverse vector
#include "sstream"
#include "deque"

using   namespace std;

int     main(void)
{
        vector<vector<pair<int, int>>>  G;
        deque<pair<int, int>>           Q;
        //queue<pair<int, int>>           Q;
        vector<int>                     dr = {-1, 0, 1, 0};
        vector<int>                     dc = { 0, 1, 0,-1};
        pair<int, int>                  start, end;
        string                          s;
        char                            c;
        int                             R, C, i, j;

        //  parsing

        cin >> R >> C;
        vector<vector<int>> DP(R, vector<int>(C, false));

        i = -1;
        while (++i < R)
        {
            cin >> s;
            vector<pair<int, int>>  temp;
            stringstream            ss(s);

            j = -1;
            while (++j < C)
            {
                ss >> c;
                temp.push_back(make_pair(-1, -1));
                if (c == 'A')   start = make_pair(i, j);
                if (c == 'B')   end = make_pair(i, j);
                DP[i][j] = (c == '#');
            }
            G.push_back(temp);
        }

        //  solve

        Q.push_back(start);
        while (!Q.empty())
        {
            int r, c;

            tie(r, c) = Q.front();
            Q.pop_front();
            i = -1;
            while (++i < 4)
            {
                int rr = r + dr[i];
                int cc = c + dc[i];

                if (rr < 0 || rr >= R || cc < 0 || cc >= C || DP[rr][cc])
                    continue;
                G[rr][cc] = make_pair(dr[i], dc[i]);
                Q.push_back(make_pair(rr, cc));
                DP[rr][cc] = true;
            }
        }

        //  answer #1

        if (!DP[end.first][end.second])
        {
            cout << "NO" << endl;
            return (0);
        }
        cout << "YES" << endl;

        //  answer #2

        vector<pair<int, int>>  res;

        while (end.first != start.first || end.second != start.second)
        {
            res.push_back( G[end.first][end.second] );
            end.first -= res.back().first;
            end.second -= res.back().second;
        }
        cout << res.size() << endl;

        //  answer #3

        reverse(res.begin(), res.end());
        s = "";
        i = -1;
        while (++i < (int) res.size())
        {
            int a = res[i].first;
            int b = res[i].second;

            if (a == -1 && b ==  0) s += 'U';
            if (a ==  0 && b ==  1) s += 'R';
            if (a ==  1 && b ==  0) s += 'D';
            if (a ==  0 && b == -1) s += 'L';
        }
        cout << s << endl;

        return (0);
}
