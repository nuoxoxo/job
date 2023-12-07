#include "iostream"
#include "vector"
#include "algorithm"
#include "sstream"

#define end endl
using	namespace std;

int	main()
{
	string	s;
	int	n;
	vector<vector<vector<int>>> M;

	while (!cin.eof() && getline(cin, s))
	{
		vector<vector<int>> m;
		if (s.find("Start") != string::npos)
		{
			vector<int> temp;
			string::size_type pos = s.find(':');
			string sub = s.substr(pos + 1, s.length());
			stringstream ss(sub);
			while (ss >> n)
			{
				temp.push_back(n);
				if (ss.peek() == ',')
					ss.ignore();
			}
			// for (int n: temp) cout << n << ' '; cout << end;
			m.push_back(temp);
		}
		if (s.find("Opera") != string::npos)
		{
			vector<int> temp;
			cout << s << end;
		}
	}
}
