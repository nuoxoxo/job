#include "iostream"

using	namespace std;

int	main(void)
{
	string	dir;
	int	x;
	int	dep, hps;
	int	aim, dep2, hps2; // part 2

	aim = dep2 = hps2 = 0; // part 2
	dep = hps = 0;
	while (cin >> dir >> x)
	{
		if (dir[0] == 'f')
		{
			hps += x;
			hps2 += x;
			dep2 += aim * x;
		}
		else
		{
			if (dir[0] == 'u')
				x *= -1;
			dep += x;
			aim += x;
		}
	}
	cout << "Star 1: " << dep * hps << endl;
	cout << "Star 2: " << dep2 * hps2 << endl;
}
