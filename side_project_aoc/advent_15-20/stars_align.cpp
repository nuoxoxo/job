#include "iostream"
#include "vector"

using	namespace std;

void	print_points(vector<vector<pair<int, int>>>& E);
void	print_star_map(vector<vector<char>>& M);

//	Drive

int	main(void)
{
	vector<vector<pair<int, int>>>	E;
	vector<vector<char>>		star_map;
	string				s;
	int				l, r, u, d, i, j, k;
	int				sec = -1;
	// int				sec = 120;

	while (getline(cin, s))
	{
		int		a, b, c, d;

		sscanf(s.c_str(), "position=<%d,%d> velocity=<%d,%d>", &a, &b, &c, &d);
		// cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
		E.push_back({make_pair(a, b), make_pair(c, d)});
	}
	// print_points(E);
	l = (int) 1e9;
	r = (int) -1e9;
	u = (int) 1e9;
	d = (int) -1e9;
	for (vector<pair<int, int>> it: E)
	{
		l = it[0].first < l ? it[0].first : l;
		r = it[0].first > r ? it[0].first : r;
		u = it[0].second < u ? it[0].second : u;
		d = it[0].second > d ? it[0].second : d;
	}
	// cout<<"Limits: "<<l<<' '<<r<<' '<<u<<' '<<d<<endl;
	i = u - 1;

	//int count = 0;

	//while (++i < d)
	while (++i < d + 1)
	{
		vector<char>	temp;

		j = l - 1;
		// while (++j < r)
		while (++j < r + 1)
		{
			bool		in = false;

			for (vector<pair<int, int>> it: E)
			{
				if (it[0].first == j && it[0].second == i)
					in = true;
			}
			if (in)
				temp.push_back('#');
			else
				temp.push_back('.');
		}
		star_map.push_back(temp);
	}

	// print_star_map(star_map);

	cout << "Ready. \n";

	while (++sec < 10)
	{
		cout << sec << endl;
		k = -1;
		while (++k < (int) E.size())
		{
			E[k][0].first += E[k][1].first;
			E[k][0].second += E[k][1].second;
		}
		k = -1;
		i = u - 1;
		while (++i < d)
		{
			vector<char>	temp;

			j = l - 1;
			while (++j < r)
			{
				bool		in = false;

				for (vector<pair<int, int>> it: E)
				{
					if (it[0].first == j && it[0].second == i)
						in = true;
				}
				if (in)
					temp.push_back('#');
				else
					temp.push_back('.');
			}
			star_map[++k] = temp;
		}
		// print_star_map(star_map);
	}
}	

//	help

void	print_star_map(vector<vector<char>>& M)
{
	/*
	for (vector<char> r: M)
	{
		for (char c: r)
			cout << c;
		cout << '\n';
	}
	cout << endl;
	*/

	int	l = (int) 1e9;
	int	r = (int) -1e9;
	int	u = (int) 1e9;
	int	d = (int) -1e9;
	int	h = (int) M.size();
	int	w = (int) M[0].size();
	int	row, col;

	row = -1;
	while (++row < h)
	{
		col = -1;
		while (++col < w)
		{
			if (M[row][col] == '#')
			{
				cout << row << ' ' << col << endl;
				l = l > col ? col : l;
				r = r < col ? col : r;
				u = u > row ? row : u;
				d = d < row ? row : d;
			}
		}
	}
	cout<<"limits: "<<l<<' '<<r<<' '<<u<<' '<<d<<endl;
	row = u - 1;
	// while (++row < d)
	while (++row < d + 1)
	{
		col = l - 1;
		while (++col < r + 1)
		{
			cout << M[row][col];
		}
		cout << '\n';
	}
	cout << endl;
	
}

void	print_points(vector<vector<pair<int, int>>>& E)
{
	for (vector<pair<int, int>> it: E)
	{
		cout << it[0].first << ' ' << it[0].second << ' ' 
		     << it[1].first << ' ' << it[1].second << endl;
	}
}
