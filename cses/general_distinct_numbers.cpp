#include "iostream"
#include "set"
using	namespace std;
int	main()
{
	set<int>	S;
	int		n, x; 
	cin >> n;
	while (cin >> x)	S.insert(x);
	cout << S.size();
}
