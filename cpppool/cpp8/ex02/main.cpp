#include "MutantStack.hpp"
#include "color.hpp"
#include "cstdlib" // rand

int	main()
{
	int	i = -1;

	std::cout << GREEN "Test :: " << ++i << " :: subject " nl2reset;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		//[...]

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;

		std::cout << LOWKEY "printing stack ..." nl RESET;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int>	s(mstack);
		std::cout << nl;
	}
	std::cout << GREEN"\nTest :: " << ++i << " :: reverse iterator " nl2reset;
	{
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);

		//[...]

		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();

		++it;
		--it;

		std::cout << LOWKEY "printing stack backwards..." nl RESET;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int>	s(mstack);
	}
	/*
	std::cout << GREEN "Test :: " << ++i << " :: emplace() " nl2reset;
	{
		MutantStack<int>	E;

		E.emplace(5);
		E.emplace(17);
		std::cout << mstack.top() << std::endl;
		E.emplace(3);
		E.emplace(42);

		MutantStack<int>::reverse_iterator it = E.rbegin();
		MutantStack<int>::reverse_iterator ite = E.rend();

		++it;
		--it;

		std::cout << LOWKEY "printing stack ..." nl RESET;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	*/
	std::cout << GREEN "\nTest :: " << ++i << " :: pop & top " nl2reset;
	{
		MutantStack<int>		mstack;
		MutantStack<int>::iterator 	it;
		MutantStack<int>::iterator 	ite;

		mstack.push(42);
		mstack.push(43);
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

		it = mstack.begin();
		ite = mstack.end();

		std::cout << LOWKEY "printing stack " nl RESET;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << GREEN "\nTest :: " << ++i << " :: push & size " nl2reset;
	{
		MutantStack<int>		mstack;
		MutantStack<int>::iterator 	it;
		MutantStack<int>::iterator 	ite;

		int		N = 1000;

		std::cout << "Trying size: "<< N << std::endl;
		srand(time(0));
		while (--N > -1)
			mstack.push((int) std::rand() % 1000);
	
		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

		mstack.pop();

		std::cout << "Top: "<< mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;

		it = mstack.begin();
		ite = mstack.end();

		std::cout << LOWKEY "printing stack " nl RESET;
		/*while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}*/
	}
}
