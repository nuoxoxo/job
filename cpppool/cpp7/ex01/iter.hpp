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

#ifndef ITER_HPP
# define ITER_HPP

# include "iostream"
# include "string"

# define LOWKEY	"\033[0;2m"
# define GREEN	"\033[0;32m"
# define RESET	"\033[0;0m"
# define nl "\n"

template<typename T>
void	iter(T * arr, size_t len, void (*f)(T &))
{
	if (!arr || !f)
		return ;

	size_t	i = -1;

	while (++i < len)
		f(arr[i]);
}

template <typename T>
void	print(T & elem)
{
	std::cout << elem << LOWKEY " (" << __FUNCTION__ << ") \n" RESET;
}

template <typename T>
void	left_shift_1(T & elem)
{
	std::cout << LOWKEY "(" << __FUNCTION__ << ") \n" RESET;

	try
	{
		elem <<= 1;
	}
	catch (std::exception(& e))
	{
		std::cerr << e.what() << nl;
		;;
	}
}

template <typename T>
void	right_shift_2(T & elem)
{
	std::cout << LOWKEY "(" << __FUNCTION__ << ") \n" RESET;

	try
	{
		elem >>= 2;
	}
	catch (std::exception(& e))
	{
		std::cerr << e.what() << nl;
		;;
	}
}

// failed test
/*template <typename T>
void	toupper(T & elem)
{
	std::cout << LOWKEY "(" << __FUNCTION__ << ") \n" RESET;

	try
	{
		if (elem < 123 && elem > 86 )
			elem -= 32;
	}
	catch (std::exception(& e))
	{
		std::cerr << e.what() << nl;
		;;
	}
}*/

#endif
