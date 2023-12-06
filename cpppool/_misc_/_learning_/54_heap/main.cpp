#include "iostream"

#define ylo "\033[0;33m"
#define cyn "\033[0;36m"
#define noc "\033[0m"
#define Size 3

class	myVector
{
public:
	int	x, y, z;
};

// overload

std::ostream & operator << (std::ostream & stream, const myVector & v)
{
	stream
	<< "x: " << v.x << '\t' << & v.x << '\n'
	<< "y: " << v.y << '\t' << & v.y << '\n'
	<< "z: " << v.z << '\t' << & v.z << '\n';

	return stream;
}

// drive

int	main()
{
	// Stack allocation

	int		stack_value = 42;
	char		stack_array[Size];
	myVector	stack_vec;

	memset(stack_array, 'c', Size);
	stack_vec.x = -1;
	stack_vec.y = 0;
	stack_vec.z = 1;

	std::cout << ylo "\n======\t Stack \t====== \n\n" noc;
	std::cout << stack_value << '\t';
	std::cout << & stack_value << "\n";
	for (int i = 0; i < Size; i++)
	{
		std::cout << stack_array[i];
		if (i ^ Size - 1)
			std::cout << ' ';
		else
			std::cout << '\t';
	}
	std::cout << & stack_array << "\n\n";
	std::cout << cyn "stack_vec: " noc << & stack_vec << "\n\n";
	std::cout << stack_vec;

	// Heap allocation

	int		*heap_value = new int();
	char		*heap_array = new char[Size];
	myVector	*heap_vec = new myVector();

	*heap_value = 42;
	memset(heap_array, 'c', Size);
	heap_vec->x = -1;
	heap_vec->y = 0;
	heap_vec->z = 1;

	std::cout << ylo "\n======\t Heap \t====== \n\n" noc;
	std::cout << * heap_value << '\t';
	std::cout << & heap_value << "\n";
	
	for (int i = 0; i < Size; i++)
	{
		std::cout << heap_array[i];
		if (i ^ Size - 1)
			std::cout << ' ';
		else
			std::cout << '\t';
	}
	std::cout << & heap_array << "\n\n";
	std::cout << cyn "heap_vec: " noc << & heap_vec << "\n\n";
	std::cout << * heap_vec;

	// Delete Heap-allocated memory

	delete	[] heap_array;
	delete	heap_value;
	delete	heap_vec;

	// Footnote

	std::cout << ylo "\n"
	<< "* Note the diff btw 2 blocks of addresses \n"
	<< "** Also note that for every 'new' keyword we have used,  \n"
	<< "** we free with operator 'delete' the mem it created. \n"
	noc << std::endl;
}
