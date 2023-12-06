#include "iostream"
#include "vector"

using	namespace std;

int	main()
{
	vector<int>	p(1);

	p[0] = 42;
	cout << p[0] << '\n';
	cout << p.size() << " (size)\n";
}
