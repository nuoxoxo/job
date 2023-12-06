/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                             ~  ~  ~  ~  ~    ~                             */
/*                              ~    _ ~ _   o>                               */
/*                             ~  \ / \ / \ /  ~                              */
/*                              ~  ~      ~    ~                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                   Array                                    */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "Array.hpp"
#define MAX 1024
#define LOWKEY "\033[0;2m"
#define GREEN "\033[0;32m"
#define RESET "\033[0;0m"
#define nl "\n"
#define nl2 "\n\n"

int	main()
{
	int	i = -1;

	std::cout << GREEN "Test :: " << ++i << " :: default init(0) \n\n" RESET;
	{
		Array<int>	arr(2);

		arr.printer();
		std::cout << arr << std::endl;
	}
	std::cout << GREEN "Test :: " << ++i << " :: sequence filled \n\n" RESET;
	{
		Array<int>	arr(3);
		int		i = 3;

		while (--i > -1)
			arr[2 - i] = i;
		arr.printer();
		std::cout << arr << std::endl;
	}
	std::cout << GREEN "Test :: " << ++i << " :: out-of-bound index \n\n" RESET;
	{
		Array<int>	arr(3);
		int		i = 3;

		while (--i > -1)
			arr[2 - i] = i;
		try {
			std::cout << arr[10] << std::endl;
		} catch (const std::exception & e) {
			std::cerr << e.what() << nl;
		}
		
		try {
			std::cout << arr[4] << std::endl;
		} catch (const std::exception & e) {
			std::cerr << e.what() << nl;
		}
		
		std::cout << nl;
	}
	std::cout << GREEN "Test :: " << ++i << " :: negative index \n\n" RESET;
	{
		Array<int>	arr(3);
		int		i = 3;

		while (--i > -1)
			arr[2 - i] = i;
		try {
			std::cout << arr[-1] << std::endl;
		} catch (const std::exception & e) {
			std::cerr << e.what() << nl2;
		}
	}
	std::cout << GREEN "Test :: " << ++i << " :: cout const int [] \n\n" RESET;
	{
		Array<int>	arr(9);
		int		i = 9;

		while (--i > -1)
			arr[8 - i] = i;

		Array<int> const const_arr(arr);

		std::cout << "array :\n" << arr << nl;
		std::cout << "const copy:\n" << const_arr << nl;
	}
	std::cout << GREEN "Test :: " << ++i << " :: copy not affected \n\n" RESET;
	{
		Array<int>	arr(9);
		int		i = 9;

		while (--i > -1)
			arr[8 - i] = i;

		Array<int> const const_arr(arr);

		i = 9;
		while (--i > -1)
			arr[8 - i] *= 10;

		std::cout << "array :\n" << arr << nl;
		std::cout << "const copy:\n" << const_arr << nl;

	}
	std::cout << GREEN "Test :: " << ++i << " :: size / length \n\n" RESET;
	{
		{
			Array<int>	arr(MAX);

			std::cout << "size:\t" << arr.size() << nl;
			std::cout << "length:\t" << arr.length() << nl2;
		}
		{
			Array<int>	arr(MAX * 64);

			std::cout << "size:\t" << arr.size() << nl;
			std::cout << "length:\t" << arr.length() << nl2;
		}
	}
	std::cout << GREEN "Test :: " << ++i << " :: float array \n\n" RESET;
	{
		{
			Array<float>	arr(3);

			arr[0] = 1.0f;
			arr[1] = 3.1415926f;
			arr[2] = 42.42f;
			std::cout << arr;
			arr.printer();
			std::cout << nl;
		}
	}
	std::cout << GREEN "Test :: " << ++i << " :: accessing empty array \n\n" RESET;
	{
		{
			Array<int>	arr(0);

			try	// writing
			{
				arr[0] = 42;
				arr[1] = 43;
				std::cout << arr;
				arr.printer();
			}
			catch (std::exception & e)
			{
				std::cout << LOWKEY "(try writing) " nl RESET
					  << e.what() << nl
					  << LOWKEY"an exception that must be caught"RESET nl2;
			}

			try	// reading
			{
				std::cout << arr[0] << nl;
				std::cout << arr[1] << nl2;
				std::cout << arr;
				arr.printer();
			}
			catch (std::exception & e)
			{
				std::cout << LOWKEY"(try reading) " nl RESET
					  << e.what() << nl
					  << LOWKEY"an exception that must be caught"RESET nl2;
			}

		}
	}
	// Just not working
	/*
	std::cout << GREEN "Test :: " << ++i << " :: string array \n\n" RESET;
	{
		try
		{
			Array<std::string>	arr(3);

			arr[0] = "to";
			arr[1] = "the";
			arr[2] = "lighthouse";
			std::cout << arr;
			arr.printer();
		}
		catch (const std::exception & e)
		{
			std::cerr << e.what() << nl;
		}
		std::cout << nl;
	}
	*/
	std::cout << GREEN "Test :: " << ++i << " :: Just a Reminder \n\n" RESET;
	{
		std::cout << GREEN "- Use valgrind -\n\n" RESET;
	}
}

