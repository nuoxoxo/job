#include "iostream"

using namespace std;

class	_Point_
{
	//public:
		int	a, b, v;
};

void	print(_Point_ & p);

//	drive

int	main()
{
	_Point_		point;

	point.a = 32;
	point.b = 64;
	point.v = 2;
	print(point);
	return (std::cin.get(), 0);
}

//

void	print(_Point_ & p)
{
	cout << "a: " << p.a << '\n';
	cout << "b: " << p.b << '\n';
	cout << "v: " << p.v << " km/s " << '\n';
}
