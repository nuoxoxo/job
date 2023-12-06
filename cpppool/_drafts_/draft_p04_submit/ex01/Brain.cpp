/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   {}.cpp                                             :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


// canon	done

Brain::Brain()
{
	print_canon(std::string(__FUNCTION__), "Constructor");
}

Brain::~Brain()
{
	print_canon(std::string(__FUNCTION__), "Destructor");
}

Brain::Brain(const Brain & dummy)
{
	*this = dummy;

	print_canon(std::string(__FUNCTION__), "Copy constructor");

}

Brain & Brain::operator = (const Brain & dummy)
{
	int		i = -1;
	
	while (++i < B_SIZE)
	{
		m_idea[i] = dummy.m_idea[i];
	}

	print_canon(std::string(__FUNCTION__), "Copy assignment constructor");

	return (*this);

}

// method

void	Brain::makeSound() const
{
	std::string	sound_of_a_brain[3] = \
	{
		"\"tssstsss... (white noise) \"",
		"\"pip!~ pip!~... (brainwave) \"", 
		"\"tick, tock... (dr. manhattan) \""
	};

	int n = (int) rand() % 3;

	std::cout
	<< "some brain: " YELL
	<< sound_of_a_brain[n] << REST nl;
}


// getter . setter

const std::string	& Brain::getIdea(int i) const
{
	// std::cout << LOWKEY << __FUNCTION__ << called REST;
	
	/*
	if (i < 0 || i >= B_SIZE)
	{
		std::cout << "invalid index: " << i
		<< ". valid range: 0 - " << B_SIZE << ". \n";
		return (nullptr); // (??)
	}

	return m_idea[i];
	*/

	return m_idea[i % B_SIZE];
}

void	Brain::setIdea(int i, std::string s)
{
	if (i < 0 || i >= B_SIZE)
	{
		std::cout << "invalid index: " << i
		<< ". valid range: 0 - " << B_SIZE << ". \n";
		return ;
	}
	m_idea[i] = s;
}
