#include "iostream"
#include "string"
#include "cstdlib"
#include "cstdint"
#include "cassert"

#define YELL "\033[0;33m"
#define GREEN "\033[0;32m"
#define RESET "\033[0;0m"
#define TICK GREEN"assertion passed ✓ \n\n"RESET

// define

struct	Data
{
	std::string	core;
	int		r, c;

	void	existence()
	{
		std::cout
		<< "content:\t" << core
		<< "\naddress:\t" << this
		<< "\nx coordinate:\t" << c
		<< "\ny coordinate:\t" << r
		<< "\n";
	};
};

static	Data *deserialize(uintptr_t _) {
	return (reinterpret_cast<Data*>(_));
}

static	uintptr_t serialize(Data * _) {
	return (reinterpret_cast<uintptr_t>(_));
}

// drive

int	main(int c, char **v)
{
	std::string	core = c > 1 ? std::string(v[1]) : "Dasein";

	std::cout << GREEN "Test 0 :: casted to uint and back \n\n" RESET;
	{
		Data	dat;

		dat.core = core;
		srand(time(0));
		dat.r = (int) rand() % 42;
		dat.c = (int) rand() % 42;
		dat.existence();		
		
		std::cout 
		<< "address & dat \t"
		<< YELL << & dat << RESET "\n\n";

		Data	*D = deserialize(serialize(& dat));

		std::cout
		<< "{ Data	*D = deserialize(serialize(& data)) } \n\n";

		D->existence();

		std::cout 
		<< "address D \t"
		<< YELL << D << RESET "\n";

		assert(D == & dat); /// XXX
		std::cout << TICK;
	}
	std::cout << GREEN "Test 1 :: idem but written as 2 lines \n\n" RESET;
	{
		Data	dat;

		dat.core = core;
		srand(time(0));
		dat.r = (int) rand() % 42;
		dat.c = (int) rand() % 42;
		dat.existence();

		std::cout 
		<< "address & dat \t"
		<< YELL << & dat << RESET "\n\n";

		uintptr_t	U = serialize(& dat);
		Data		*D = deserialize(U);

		std::cout
		<< "{ uintptr_t  U = serialize(& dat); } \n"
		<< "{ Data       *D = deserialize(U); } \n\n";

		D->existence();

		std::cout 
		<< "address D \t"
		<< YELL << D << RESET "\n";
		
		std::cout
		<< "uint pointer \t"
		<< YELL << U << "\n" RESET;

		assert(D == & dat); /// XXX
		std::cout << TICK;

	}
	std::cout << GREEN "Test 2 :: using pointer, see 3 addresses \n\n" RESET;
	{
		Data	*dat = new Data;

		dat->core = core;
		srand(time(0));
		dat->r = (int) rand() % 42;
		dat->c = (int) rand() % 42;
		dat->existence();		
		
		std::cout 
		<< "address dat \t"
		<< YELL << dat << RESET "\n"
		<< "address & dat \t"
		<< YELL << & dat << RESET "\n\n";

		uintptr_t	U = serialize(dat);
		Data		*D = deserialize(U);

		std::cout
		<< "{ Data      *dat = new Data; } \n"
		<< "{ uintptr_t U = serialize(& dat); } \n"
		<< "{ Data*     D = deserialize(U); } \n"
		<< "{ delete    dat; } \n\n";

		D->existence();

		std::cout 
		<< "address D \t"
		<< YELL << D << RESET "\n"
		<< "address & D \t"
		<< YELL << & D << RESET "\n";

		std::cout
		<< "uint pointer\t"
		<< YELL << U << "\n" RESET;

		assert(D == dat); /// XXX
		std::cout << TICK;

		delete dat;
	}
}

