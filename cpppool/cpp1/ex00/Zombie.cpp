/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {}

//

std::string	Zombie::get_name(void) const
{
	return (this->name);
}

void	Zombie::label(void) const
{
	std::cout << _GREEN_ << this->name << _REST_; // diff signs
	// subject dictates: no < > 
	
	/* using different signs */
	// std::cout << _GREEN_ "﹤" << this->name << "﹥" _REST_; // diff signs
	/* to cleanup on submit */
	// std::cout << '<' << this->name << '>' << ' '; // norm -gt -lt
}

void	Zombie::announce(void) const
{
	Zombie::label();
	std::cout << ": BraiiiiiiinnnzzzZ... \n";
}

Zombie::~Zombie(void)
{
	Zombie::label();
	std::cout << " is dead. \n";
}

/* <------8<------ tester functions ------------------> */

void	storyline_1(void)
{
	std::cout << "\nStoryline (1)\n";
	std::cout << _YELLOW_ "\n[ Meet Matthew, the first ";
	std::cout << "man-made psychic-vampire of ";
	std::cout << "the new era. ]\n" _REST_ ;
	
	std::cout << _CYAN_ "[ Matthew is created on the ";
	std::cout << _RED_ "\"Stack\"" _REST_ ;
	
	std::cout << _CYAN_ " ]\n[ ie. built with ";
	std::cout << _RED_ _ITAL_"\"Zombie name(name)\"" _REST_ ;
	
	std::cout << _CYAN_ " ]\n\n" _REST_ ;

}

void	storyline_2(void)
{
	std::cout << "\nStoryline (2)\n";
	
	std::cout << _YELLOW_ "\n[ Here's Luke. Luke is different... ]\n";
	std::cout << "[ While Matthew is a vampire, Luke is a ghost. ";
	std::cout << "...A real one. ]\n" _REST_ ;
	
	std::cout << _CYAN_ "[ Luke is created on the ";
	std::cout << _RED_ "\"Heap\"" _REST_ ;
	
	std::cout << _CYAN_ " ]\n[ ie. built by using the ";
	std::cout << _RED_ _ITAL_ "\"new\"" _REST_ ;
	
	std::cout << _CYAN_ " keyword ]\n\n" _REST_ ;
}

void	storyline_3(void)
{
	std::cout << "\nStoryline (3)\n";
	std::cout << _YELLOW_ "\n[ Paul is born... ";
	std::cout << "and dies instantly. ]\n\n" _REST_;
}

void	storyline_4(void)
{
	std::cout << "\nStoryline (4)\n";
	
	std::cout << _YELLOW_ "\n[ Let's kill Luke before we go. ]\n";
	std::cout << "[ Because he is the ";
	std::cout << _ITAL_ _RED_ "heap " _REST_ << _YELLOW_ "guy. ]\n";
}


