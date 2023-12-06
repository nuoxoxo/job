#include "iostream"

#define Print(add, val) std::cout << add << ' ' << val << std::endl 
#define end2 "\n\n"
#define end "\n"

void	Increment_type1(int* n) { ++(*n); }
void	Increment_type2(int& n)	{ ++n; }

//	Drive

int	main()
{
	int	num = 42;
	int &	ref = num;

	// we print out the pointer address and its value for each pointer

	std::cout << &ref << ' ' << ref << end2;

	// change of value

	ref = 10;

	std::cout << &ref << ' ' << ref << end;
	std::cout << &num << ' ' << num << end2;

	// increment the alias (ref) of num -- non-reference way

	Increment_type1( & ref);
	std::cout << &ref << ' ' << ref << end;
	std::cout << &num << ' ' << num << end2;

	// increment using Reference

	Increment_type2(ref);
	std::cout << & ref << ' ' << ref << end;
	std::cout << &num << ' ' << num << end;
}
