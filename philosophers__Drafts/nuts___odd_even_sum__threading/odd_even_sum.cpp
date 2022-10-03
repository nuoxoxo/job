#include "iostream"
#include "thread"
#include "chrono"
#include "algorithm"

using namespace std;
//using namespace std::chrono;

#define ull unsigned long long

void	add_if_even(ull start, ull end);
void	add_if_odd(ull start, ull end);

ull	even_sum = 0;
ull	odd_sum = 0;

int	main()
{
	ull		start = 0;
	ull		end = 1e9;

	//auto	start_time = high_resolution_clock::now();

	/* setup thread */

	std::thread	t1(add_if_even, start, end);
	std::thread	t2(add_if_odd, start, end);

	t1.join();
	t2.join(); // join . asks main to wait for thread to complete

	/* end setup */

//	auto	stop_time = high_resolution_clock::now();
//	auto	duration = duration_cast<microseconds>(stop_time - start_time);

	cout << "odd sum  : " << odd_sum << endl;
	cout << "even sum : " << even_sum << endl;

	//cout << "elapsed time: " << duration.count() << endl;

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
