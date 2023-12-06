/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   CPP08X00.hpp                                       :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/02/01 13:34:51 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP08X00_HPP
# define CPP08X00_HPP

# include "iostream"
# include "set"

# define LOWKEY "\033[0;2m"
# define GREEN "\033[0;32m"
# define RESET "\033[0;0m"
# define MAX 10
# define SIZE 4

//	colors

# define ITAL	"\033[3m"
# define LOWKEY	"\033[0;2m"
# define WHITE	"\033[1;37m"
# define CYAN	"\033[0;36m"
# define YELL	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define MAG	"\033[0;35m"

# define RESET	"\033[0;0m"

# define TICK	GREEN" ✓"RESET
# define CROSS	RED" ✘"RESET


//	formatting

# define called " called\n"
# define inside "\ninside "
# define notfound "element not found: "
# define endpoint "iterator now points to _.end()"

# define nl2reset " \n\n" RESET
# define nl2 " \n\n"
# define nl " \n"

template <typename Iter>
Iter	nextIter(Iter it) { return ++it; }

template<typename T>
void	print_vector(T & arr)
{
	int	len = (int) arr.size();
	int	i = -1;

	std::cout << "vector:\t[";
	while (++i < len)
		std::cout << arr[i] << (i == len - 1 ? "]\n" : ", ");
	std::cout << "\n";
}

void	print_set(std::set<std::string> S)
{
	std::set<std::string>::iterator	it = S.begin();

	std::cout << "set:\t[";
	while (it != S.end())
	{
		std::cout << *it << (nextIter(it) == S.end() ? "]\n" : ", ");
		++it;
	}
	std::cout << "\n";
}

void	print_set(std::set<int> S)
{
	std::set<int>::iterator	it = S.begin();

	std::cout << "set:\t[";
	while (it != S.end())
	{
		std::cout << *it << (nextIter(it) == S.end() ? "]\n" : ", ");
		++it;
	}
	std::cout << "\n";
}

/*
template<typename T>
void	print_set(T S)
{
	typename std::set<T>::iterator	it = S.begin();

	std::cout << "set:\t[";
	while (it != S.end())
	{
		std::cout << *it << (next(it) == S.end() ? "]\n" : ", ");
		++it;
	}
	std::cout << "\n";
}
*/

template<typename T>
void	print_target(T target)
{
	std::cout << "target:\t" YELL << target << nl RESET;
}



#endif
