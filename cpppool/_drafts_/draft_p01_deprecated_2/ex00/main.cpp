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

static void	storyline_1(void);
static void	storyline_2(void);
static void	storyline_3(void);
static void	storyline_4(void);

int	main()
{
	Zombie		*luke = newZombie("Luke");
	Zombie		matt("Matthew");

	storyline_1();
	matt.announce();

	// ------8<------

	storyline_2();
	luke->announce();

	// ------8<------

	storyline_3();
	randomChump("Paul");

	// ------8<------

	storyline_4();
	delete	luke;
}

//

static void	storyline_1(void)
{
//	std::cout << "\n(1)";
	std::cout << _YELLOW_ "\n[ Meet Matthew, the first ";
	std::cout << "man-made psychic-vampire of ";
	std::cout << "the new era. ]\n" _REST_ ;
	std::cout << _CYAN_ "[ Matthew is created on the ";
	std::cout << _RED_ "\"Stack\"" _REST_ ;
	std::cout << _CYAN_ " ]\n[ ie. built with ";
	std::cout << _RED_ _ITAL_"\"Zombie name(name)\"" _REST_ ;
	std::cout << _CYAN_ " ]\n\n" _REST_ ;

}

static void	storyline_2(void)
{
//	std::cout << "\n(2)";
	std::cout << _YELLOW_ "\n[ Here's Luke. Luke is different... ]\n";
	std::cout << "[ While Matthew is a vampire, Luke is a ghost. ";
	std::cout << "...A real one. ]\n" _REST_ ;
	std::cout << _CYAN_ "[ Luke is created on the ";
	std::cout << _RED_ "\"Heap\"" _REST_ ;
	std::cout << _CYAN_ " ]\n[ ie. built by using the ";
	std::cout << _RED_ _ITAL_ "\"new\"" _REST_ ;
	std::cout << _CYAN_ " keyword ]\n\n" _REST_ ;
}

static void	storyline_3(void)
{
//	std::cout << "\n(3)";
	std::cout << _YELLOW_ "\n[ Paul is born... ";
	std::cout << "and dead almost instantly. ]\n\n" _REST_;
}

static void	storyline_4(void)
{
//	std::cout << "\n(4)";
	std::cout << _YELLOW_ "\n[ Before we go, let's ";
	std::cout << "KILL Luke. ]\n[ Just because he is the ";
	std::cout << _ITAL_ _RED_ "heap " _REST_ << _YELLOW_ "guy. ]\n";
	std::cout << "[ ...But we didn't kill Matthew. ]\n\n" _REST_;
}
