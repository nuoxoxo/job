#include "iostream"
#include "cstdio"
#include "vector"
#include "deque"
#include "algorithm"
#include "set"
#include "tuple"

using	namespace std;

int	BFS(int, int, int, int, int, int, int time);

int	main()
{
	int OneedsO, CneedsO, OBneedsO, OBneedsC, GneedsO, GneedsOB, id;
	int res, tmp = 0;
	string s;

	res = 0;
	while (getline(cin, s) && !cin.eof())
	{
		sscanf(s.c_str(),
		"Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.", &id, &OneedsO, &CneedsO, &OBneedsO, &OBneedsC, &GneedsO, &GneedsOB);
		cout << id << ": "
		<< OneedsO << ' ' << CneedsO << ' '
		<< OBneedsO << ' ' << OBneedsC << ' '
		<< GneedsO << ' ' << GneedsOB << endl;
		tmp = BFS(OneedsO, CneedsO, OBneedsO, OBneedsC, GneedsO, GneedsOB, 24);
		res += tmp * id;
		cout << "res: " << res << endl;
	}
	cout << res << endl;
}

//

int	BFS(int Co, int Cc, int Co1, int Co2, int Cg1, int Cg2, int T)
{
	// deque<vector<int>> Q;
	// set<vector<int>> SEEN;
	deque<tuple<int,int,int,int,int,int,int,int,int>> Q;
	set<tuple<int,int,int,int,int,int,int,int,int>> SEEN;
	Q.push_back(make_tuple( 0, 0, 0, 0, 1, 0, 0, 0, T ));
	int best = 0;
	while (!Q.empty())
	{
		// cout << Q.size() << endl;
		// vector<int> state = Q.front();
		tuple<int,int,int,int,int,int,int,int,int> state = Q.front();
		Q.pop_front();
		/*int o = state[0], c = state[1], ob = state[2], g = state[3],
		r1 = state[4], r2 = state[5], r3 = state[6], r4 = state[7],
		t = state[8];*/
		int o = get<0>(state), 
		    c = get<1>(state),
		    ob = get<2>(state), 
		    g = get<3>(state),
		    r1 = get<4>(state), 
		    r2 = get<5>(state),
		    r3 = get<6>(state), 
		    r4 = get<7>(state), 
		    t = get<8>(state);
		// cout<<o<<c<<ob<<g<<' '<<r1<<r2<<r3<<r4<<' '<<t<<endl;
		if (g > best)
			best = g;
		if (!t)
			continue ;
		vector<int> tmp{Co, Cc, Co1, Cg1};
		int Core = *max_element(tmp.begin(), tmp.end());
		// cout << "Core : " << Core << endl;
		if (r1 >= Core)
			r1 = Core;
		if (r2 >= Co2)
			r2 = Co2;
		if (r3 >= Cg2)
			r3 = Cg2;
		if (o >= t*Core - r1*(t-1))
		{
			o = t*Core - r1*(t-1);
		}
		if (c >= t*Co2 - r2 * (t-1))
		{
			c = t*Co2 - r2*(t-1);
		}
		if (ob >= t*Cg2 - r3*(t-1))
		{
			ob = t*Cg2 - r3*(t-1);
		}
		state = make_tuple(o, c, ob, g, r1, r2, r3, r4, t);
		// if (seen.contains(state))
		if (find(SEEN.begin(), SEEN.end(), state) != SEEN.end())
			continue ;
		SEEN.insert(state);
		if ((int) SEEN.size() % 1000000 == 0)
			cout << t << ' ' << best << ' ' << SEEN.size() << endl;
		Q.push_back(
		make_tuple(o + r1, c + r2, ob + r3, g + r4, r1, r2, r3, r4, t - 1));
		// int Oo, int Co, int OBo, int OBc, int Go, int Gc, int time
		if (o >= Co)
			Q.push_back(
			make_tuple(o-Co+r1, c+r2, ob+r3, g+r4, r1+1,r2,r3,r4,t-1));
		if (o >= Cc)
			Q.push_back(
			make_tuple(o-Cc+r1, c+r2, ob+r3, g+r4, r1,r2+1,r3,r4,t-1));
		if (o >= Co1 && c >= Co2)
			Q.push_back(
			make_tuple(o-Co1+r1, c-Co2+r2, ob+r3, g+r4, r1,r2,r3+1,r4,t-1));
		if (o >= Cg1 && ob >= Cg2)
			Q.push_back(
			make_tuple(o-Cg1+r1, c+r2, ob-Cg2+r3, g+r4, r1,r2,r3,r4+1,t-1));
	}
	return best;
}

/*int	BFS(int Oo, int Co, int OBo, int OBc, int Go, int Gc, int time)
{
	// deque<vector<int>> states{{0, 0, 0, 0, 1, 0, 0, 0, time}};
	deque<vector<int>> states;
	set<vector<int>> seen;
	int best = 0;
	states.push_back({ 0, 0, 0, 0, 1, 0, 0, 0, time });
	while (!states.empty())
	{
		vector<int> state = states.front();
		// auto state = states.front();
		states.pop_front();
		int o = state[0], c = state[1], ob = state[2], g = state[3],
		r1 = state[4], r2 = state[5], r3 = state[6], r4 = state[7],
		t = state[8];
		best = best > g ? best : g;
		if (!t)
			continue ;
		vector<int> tmp{Oo, Co, OBo, Go};
		int Core = *max_element(tmp.begin(), tmp.end());
		//cout << "Core : " << Core << endl;
		if (r1 >= Core)
			r1 = Core;
		if (r2 >= OBc)
			r2 = OBc;
		if (r3 >= Gc)
			r3 = Gc;
		if (o >= t * Core - r1 * (t - 1))
		{
			o = t * Core - r1 * (t - 1);
		}
		if (c >= t * OBc - r2 * (t - 1))
		{
			c = t * OBc - r2 * (t - 1);
		}
		if (ob >= t * Gc - r3 * (t - 1))
		{
			ob = t * Gc - r3 * (t - 1);
		}
		state = {o, c, ob, g, r1, r2, r3, r4, t};
		// if (seen.contains(state))
		if (find(seen.begin(), seen.end(), state) != seen.end())
			continue ;
		seen.insert(state);
		if ((int) seen.size() % 1000000 == 0)
			cout << t << ' ' << best << ' ' << seen.size() << endl;
		states.push_back(
		{o + r1, c + r2, ob + r3, g + r4, r1, r2, r3, r4, t - 1});

		// int Oo, int Co, int OBo, int OBc, int Go, int Gc, int time
		if (o >= Oo)
			states.push_back(
			{o-Oo+r1, c+r2, ob+r3, g+r4, r1+1,r2,r3,r4,t-1});
		if (o >= Co)
			states.push_back(
			{o-Co+r1, c+r2, ob+r3, g+r4, r1,r2+1,r3,r4,t-1});
		if (o >= OBo && c >= OBc)
			states.push_back(
			{o-OBo+r1, c-OBc+r2, ob+r3, g+r4, r1,r2,r3+1,r4,t-1});
		if (o >= Go && ob >= Gc)
			states.push_back(
			{o-Go+r1, c+r2, ob-Gc+r3, g+r4, r1,r2,r3,r4+1,t-1});
	}
	return best;
}*/


