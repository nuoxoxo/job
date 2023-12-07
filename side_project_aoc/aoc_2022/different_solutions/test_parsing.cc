#include "iostream"
#include "sstream"

using	namespace std;

string	parse_movement(string& s);

int	main()
{
	string s;
	if (!cin.eof())
		cin >> s;
	string movement = parse_movement(s);
	
}

string	parse_movement(string& s)
{
	stringstream ss(s);
	char c;
	string S;
	while (!ss.eof())
	{
		ss >> c;
		if (c <= '9' && c >= '0')
		{
			string temp;
			temp += c;
			while (1)
			{
				if (ss.peek() <= '9' && ss.peek() >= '0')
				{
					ss >> c;
					temp += c;
				}
				else
					break ;
			}
			S += temp;
			S += ' ';
		}
		else
		{
			S += c;
			S += ' ';
		}
	}
	return S;
}
