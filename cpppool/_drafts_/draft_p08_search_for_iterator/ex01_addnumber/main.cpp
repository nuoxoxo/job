#include "CPP08X01.hpp"
#include "Span.hpp"
#include "iostream"
#include "utility"
#include "cstdlib"
#include "algorithm"

int	main()
{
	int	i = -1;

	srand(time(0));

	std::cout << LOWKEY "Test :::::: " << ++i << " :::::: subject " nl2reset;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sspan << GREEN << sp.shortestSpan() << nl RESET;
		std::cout << lspan << GREEN << sp.longestSpan() << RESET nl2;
	}
	std::cout << LOWKEY "Test :::::: " << ++i << " :::::: restatement " nl2reset;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sspan << GREEN << sp.shortestSpan() << nl RESET;
		std::cout << lspan << GREEN << sp.longestSpan() << RESET nl2;

		std::pair<int, int> pmin = min_diff_pair(sp.getCore());
		std::pair<int, int> pmax = max_diff_pair(sp.getCore());
		print_pair(pmin, "shortest span");
		print_pair(pmax, "longest span");
	}
	std::cout << LOWKEY "Test :::::: " << ++i << " :::::: 10000 numbers using addNumber" nl2reset;
	{
		unsigned int	N = 10000;
		Span		sp = Span(N);
		int		left_bound = -1 * N * (N / 2);
		int		bound = N * (N / 2) - left_bound;
		int		i = -1;
		int		a;

		while (++i < (int) N)
		{
			do
			{
				a = left_bound + ((int) rand() % bound);
			}
			while
			(
				(std::find(
				sp.getCore().begin(), sp.getCore().end(), a)
				!= sp.getCore().end()) ||
				(std::find(
				sp.getCore().begin(), sp.getCore().end(), a - 1)
				!= sp.getCore().end()) ||
				(std::find(
				sp.getCore().begin(), sp.getCore().end(), a + 1)
				!= sp.getCore().end())
			);
			sp.addNumber(a);
		}

		std::cout << sspan << GREEN << sp.shortestSpan() << nl RESET;
		std::cout << lspan << GREEN << sp.longestSpan() << RESET nl2;

		std::pair<int, int> pmin = min_diff_pair(sp.getCore());
		std::pair<int, int> pmax = max_diff_pair(sp.getCore());
		print_pair(pmin, "shortest span");
		print_pair(pmax, "longest span");
	}
	std::cout << LOWKEY "Test :::::: " << ++i << " :::::: 20000 numbers using addNumber" nl2reset;
	{
		unsigned int	N = 20000;
		Span		sp = Span(N);
		int		left_bound = -1 * N * (N / 2);
		int		bound = N * (N / 2) - left_bound;
		int		i = -1;
		int		a;

		while (++i < (int) N)
		{
			do {
				a = left_bound + ((int) rand() % bound);
			} while (
				(std::find(
				sp.getCore().begin(), sp.getCore().end(), a)
				!= sp.getCore().end()) ||
				(std::find(
				sp.getCore().begin(), sp.getCore().end(), a - 1)
				!= sp.getCore().end()) ||
				(std::find(
				sp.getCore().begin(), sp.getCore().end(), a + 1)
				!= sp.getCore().end())
			);
			sp.addNumber(a);
		}

		std::cout << sspan << GREEN << sp.shortestSpan() << nl RESET;
		std::cout << lspan << GREEN << sp.longestSpan() << RESET nl2;

		std::pair<int, int> pmin = min_diff_pair(sp.getCore());
		std::pair<int, int> pmax = max_diff_pair(sp.getCore());
		print_pair(pmin, "shortest span");
		print_pair(pmax, "longest span");
	}
	std::cout << LOWKEY "Test :::::: " << ++i << " :::::: 10000 numbers - addRandomNumbers" nl2reset;
	{
		int		N = 10000;
		Span		sp = Span(N);

		sp.addRandomNumbers(N);
	
		std::cout << sspan << GREEN << sp.shortestSpan() << nl RESET;
		std::cout << lspan << GREEN << sp.longestSpan() << RESET nl2;

		std::pair<int, int> pmin = min_diff_pair(sp.getCore());
		std::pair<int, int> pmax = max_diff_pair(sp.getCore());
		print_pair(pmin, "shortest span");
		print_pair(pmax, "longest span");
	}
	std::cout << LOWKEY "Test :::::: " << ++i << " :::::: 20000 numbers - addRandomNumbers" nl2reset;
	{
		int		N = 20000;
		Span		sp = Span(N);

		sp.addRandomNumbers(N);
	
		std::cout << sspan << GREEN << sp.shortestSpan() << nl RESET;
		std::cout << lspan << GREEN << sp.longestSpan() << RESET nl2;

		std::pair<int, int> pmin = min_diff_pair(sp.getCore());
		std::pair<int, int> pmax = max_diff_pair(sp.getCore());
		print_pair(pmin, "shortest span");
		print_pair(pmax, "longest span");
	}

}
