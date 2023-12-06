#include "iostream"
#include "vector"

#define PROMPT "heredoc> "

using namespace std;

int	main()
{
	vector<string>		heredoc;
	string			delim;
	string			temp;

	cout << "cat << ";
	cin >> delim;
	// while (cin >> temp && temp != delim)
	while (getline(cin, temp) && temp != delim)
	{
		cout << PROMPT;
		heredoc.push_back(temp);
	}
	for (string s : heredoc)
	{
		if (s != "")
			cout << s << endl;
	}
	return (0);
}
