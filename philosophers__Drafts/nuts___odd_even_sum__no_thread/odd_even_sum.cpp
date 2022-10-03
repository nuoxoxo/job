#include "iostream"
#include "thread"
//#include "chrono"
#include "algorithm"

using namespace std;
using namespace std::chrono;

#define ull unsigned long long

void	add_if_even(ull start, ull end);
void	add_if_odd(ull start, ull end);

ull	even_sum = 0;
ull	odd_sum = 0;

int	main()
{
	ull	start = 0;
	ull	end = 1e6;

	//auto	start_time = high_resolution_clock::now();

	add_if_even(start, end);
	add_if_odd(start, end);

	//auto	stop_time = high_resolution_clock::now();
	//auto	duration = duration_cast<microseconds>(stop_time - start_time);

	cout << "odd sum  : " << odd_sum << endl;
	cout << "even sum : " << even_sum << endl;

	//cout << "elapsed time: " << duration.count() / 1e6 << endl;
}

void	add_if_even(ull start, ull end)
{
	ull		i;

	i = start - 1;
	while (++i < end)
	{
		if (!(i & 1))
			even_sum += i;
	}
}

void	add_if_odd(ull start, ull end)
{
	ull		i;

	i = start - 1;
	while (++i < end)
	{
		if ((i & 1) == 1)
			odd_sum += i;
	}
}
