#include "iostream"

#define end "\n"
#define end2 "\n\n"

int	main()
{
	int	num = 42;

	void	*void_ptr = &num;
	int	*int_ptr = &num;

	// then we can look at the address and value of each pointer

	std::cout << void_ptr << end;
	std::cout << *(int *) void_ptr << end2;

	std::cout << int_ptr << end;
	std::cout << *int_ptr << end2;

	// we cannot change the value for void pointer, 
	// but we can for int pointer

	*int_ptr = 11;

	std::cout << int_ptr << end;
	std::cout << *int_ptr << end;
}
