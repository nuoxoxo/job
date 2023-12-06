#include "iostream"
#include "sstream"
#include "iomanip"

#define	W0 10
#define	W1 6
#define	W2 9

int	main()
{
	std::cout << "no setw: " << "\n"
	<< "[" << 42 << "]" << "\n\n"

	<< W0 << "\n"
	<< "[" << std::setw(W0) << "]\n"
	<< "[" << std::setw(W0) << 42 << "]\n"
	<< "[" << 89 << std::setw(W0) << 12 << 34 << "]\n"
	<< "[" << 89 << 64 << std::setw(W0) << 12 << 34 << "]"
	<< "\n\n"
	
	<< W1 << '\n'
	<< "[" << std::setw(W1) << "]\n"
	<< "[" << std::setw(W1) << 42 << "]\n"
	<< "[" << 89 << std::setw(W1) << 12 << 34 << "]\n"
	<< "[" << 89 << 64 << std::setw(W1) << 12 << 34 << "]"
	<< "\n\n"

	<< W2 << '\n'
	<< "[" << std::setfill('.') << 42 << std::setw(W2) << "]\n"
	<< "[" << std::setfill('.') << 1 << 2 << 3 << 4 << "Five" << 99 << std::setw(W2)
	<< "]";
}
