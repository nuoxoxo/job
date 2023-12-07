#include <iostream>
#include <vector>

using	namespace std;

int	single(vector<int>);
int	triple(vector<int>);

int	main(void)
{
	vector<int>	dp;
	int		d, r1, r2;

	while (cin >> d)
		dp.push_back(d);
	r1 = single(dp);
	r2 = triple(dp);
	cout << "Star 1: " << r1 << endl;
	cout << "Star 2: " << r2 << endl;
}

//

int	triple(vector<int> dp)
{
	int	last3;
	int	curr3;
	int	res;
	int	i;

	last3 = dp[0] + dp[1] + dp[2];
	res = 0;
	i = 0;
	while (++i < (int) dp.size() - 2)
	{
		curr3 = dp[i] + dp[i + 1] + dp[i + 2];
		if (curr3 > last3)
			++res;
		last3 = curr3;
	}

	return (res);
}

int	single(vector<int> dp)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (++i < (int) dp.size())
		if (dp[i] > dp[i - 1])
			++res;
	return (res);
}
