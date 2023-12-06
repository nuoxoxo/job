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
/*                                 Template                                   */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "iter.hpp"
#include "iomanip"

int	main()
{
	int	i = -1;

	std::cout << GREEN "\nTest :: " << ++i << "\n\n" RESET;
	{
		const size_t	n = 3;
		std::string	arr[n] = {"good", "morning", "vietnam"};
		
		iter(arr, n, print);
		
		std::cout << "\n";
	}

	/*std::cout << GREEN "\nTest :: " << ++i << "\n\n" RESET;
	{
		const size_t	n = 3;
		std::string	arr[n] = {"good", "morning", "vietnam"};
		
		iter(arr, n, toupper);
		
		std::cout << "\n";
	}*/
	
	std::cout << GREEN "\nTest :: " << ++i << "\n\n" RESET;
	{
		const size_t	n = 4;
		int		arr[n] = {2, 4, 10, 1024};
		
		iter(arr, n, print);
		iter(arr, n, left_shift_1);
		iter(arr, n, print);
		
		std::cout << "\n";
	}
	std::cout << GREEN "Test :: " << ++i << "\n\n" RESET;
	{
		const size_t	n = 4;
		int		arr[n] = {196883, 8192, 4096, 2048};
		
		iter(arr, n, print);
		iter(arr, n, right_shift_2);
		iter(arr, n, print);
		
		std::cout << "\n";
	}
	std::cout << GREEN "Test :: " << ++i << "\n\n" RESET;
	{
		const size_t	n = 4;
		float		arr[n] = {0.1f, 42.42f, 3.1415926f, 196883.0f};
		
		std::cout << std::setiosflags(std::ios::fixed);
		std::cout << std::setprecision(7);

		iter(arr, n, print);
		
		std::cout << std::resetiosflags(std::ios::fixed);
		std::cout << "\n";
	}
	std::cout << GREEN "Test :: " << ++i << "\n\n" RESET;
	{
		const size_t	n = 4;
		double		arr[n] = {0.1, 42.42, 3.1415926, 196883.0};
		
		std::cout << std::setiosflags(std::ios::fixed);
		std::cout << std::setprecision(10);
		
		iter(arr, n, print);
		
		std::cout << std::resetiosflags(std::ios::fixed);
		std::cout << "\n";
	}
}

