#include "iostream"
#include "vector"

using	namespace std;

int	Gen(void) { return (0); }

int	main()
{
	unsigned int	len = 10000;
	vector<int>	v(len);

	generate_n(v.begin(), len, Gen);
	for (int & n: v)
		cout << n << ' ';
	cout << '\n';
}
