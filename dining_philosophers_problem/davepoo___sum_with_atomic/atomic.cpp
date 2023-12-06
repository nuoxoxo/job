#include "iostream"
#include "vector"
#include "numeric"
#include "thread"

using namespace	std;

void			adding(const vector<int>& c, int start, int end);
void			viprint(vector<int>);

long long		Sum = 0;
//atomic<long long>	Sum(0);

int	main()
{
	vector<int>	random_numbers;
	int		n;
	int		i;
	long long	STL;

	srand(time(NULL));
	n = 640000;
	i = -1;
	while (++i < n)
		random_numbers.push_back(rand());
	//viprint(random_numbers);

	std::thread	t1(adding, random_numbers, 0, n / 6);
	std::thread	t2(adding, random_numbers, n / 6 * 1, n / 6 * 2);
	std::thread	t3(adding, random_numbers, n / 6 * 2, n / 6 * 3);
	std::thread	t4(adding, random_numbers, n / 6 * 3, n / 6 * 4);
	std::thread	t5(adding, random_numbers, n / 6 * 4, n / 6 * 5);
	std::thread	t6(adding, random_numbers, n / 6 * 5, n);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	t5.join();
	t6.join();

	STL = accumulate(random_numbers.begin(), random_numbers.end(), 0LL);
	cout << STL << " (STL) \n";
	cout << Sum << " (threaded) \n";

	if (Sum ^ STL)
	{
		cout << "\u001b[31;1m ⤷ Incorrect \e[m\n";
	}
	else
	{
		cout << "\u001b[32;1m ⤷ Correct \e[m\n";
	}
}

void	adding(const vector<int>& c, int start, int end)
{
	int		i;

	i = start - 1;
	while (++i < end)
		Sum += c[i];
}

void	viprint(vector<int> c)
{
	int		i;

	i = -1;
	while (++i < (int) c.size())
	{
		cout << c[i] << ' ';
		if (i % 5 == 0)
			cout << '\n';
	}
	cout << endl;
}
