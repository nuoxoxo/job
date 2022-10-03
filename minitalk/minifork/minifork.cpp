#include "iostream"
#include "unistd.h"

int	main()
{
	int	fd = fork();

	std::cout << "\"Hello, World!\" from " << f;
	fd ? std::cout << ", a child process" : std::cout << ", the parent process" ;

	std::cout << std::endl;
	return 0 ;
}
