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

//  priority queue

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using   namespace std;
using   PL = pair<long, long>;

int     main(void)
{
        priority_queue<PL, vector<PL>, greater<PL>> Q;
        vector<PL>::iterator                        it;
        long                                        i, nodes, edges;
        PL                                          path;

        cin >> nodes >> edges;
        
        vector<vector<PL>>  E(nodes, vector<PL>{});

        i = -1;
        while (++i < edges)
        {
            long    start, end, cost;

            cin >> start >> end >> cost;
            start --;
            end --;
            E[start].push_back(make_pair(end, cost));
            //E[end].push_back(make_pair(start, c)); // one way, no need
        }

        vector<long>    D(nodes, -1);

        Q.push(make_pair(0, 0));
        while (!Q.empty())
        {
            path = Q.top(); // .1st = cost; .2nd = this path's only dest
            Q.pop();
            if (D[path.second] == -1) // if destination not visited
            {
                D[path.second] = path.first; // set vertex cost in D
                it = E[path.second].begin();
                while (it != E[path.second].end()) // .1st = dest; .2nd = cost
                {
                    Q.push(make_pair(path.first + it->second, it->first));
                    it++;
                }
            }
        }
        i = -1;
        while (++i < nodes) cout << D[i] << " ";

        return (0);
}
