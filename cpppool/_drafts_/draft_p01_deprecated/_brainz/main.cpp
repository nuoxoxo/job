/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nxu              ...   ::::::::.fi       */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

# include "iostream"
# include "string"
# include "zombie_color.hpp"

using namespace std;

/* <------8<------ Zombie class ------------------> */

class	Zombie
{

private:
	string	name;

private:
	void	label(void) const;

public:
	Zombie(string);
	virtual ~Zombie(void);

public:
	string	get_name(void) const;
	void	announce(void) const;

};


/* <------8<------ Member functioons ------------------> */


Zombie		*newZombie(string);
void		randomChump(string);

void		storyline_1(void);
void		storyline_2(void);
void		storyline_3(void);
void		storyline_4(void);

// class Zombie;
// 	cannot do that, explanation below
/*
 *	when working with a class, the compiler has to know about the class' details
 *	- not just that it exists -  
 *	the compiler needs to ensure the entire proper layout on the stack
 *	what parameters are required for the constructor, etc.
 *	that's why we CANNOT prototype classes like functions
 */


/*		drive		*/


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


/*		member functions		*/


Zombie::Zombie(string name) : name(name)
{}


string	Zombie::get_name(void) const
{ return (this->name); }


void	Zombie::label(void) const
{ cout << _green "﹤" << this->name << "﹥" _reset; }


void	Zombie::announce(void) const {
	Zombie::label();
	cout << "BraiiiiiiinnnzzzZ... \n";
}


Zombie::~Zombie(void) {
	Zombie::label();
	cout << _cyan "is dead. \n" _reset;
}


/*		non-member function		*/


Zombie	*newZombie(string name) {
	Zombie	*newZombie = new Zombie(name);
	return (newZombie);
}


void	randomChump(string name) {
	Zombie	*random_zombie = newZombie(name);
	random_zombie->announce();
	delete	random_zombie;
}


/*		storyline		*/


void	storyline_1(void)
{
	cout << _yellow "\n[ Meet Matthew, the first ";
	cout << "man-made psychic-vampire of ";
	cout << "the new era. ]\n" _reset ;
	cout << _mag "[ Matthew is created on the ";
	cout << _red "\"Stack\"" _reset ;
	cout << _mag " ]\n[ ie. built with ";
	cout << _red _ital"\"Zombie name(name)\"" _reset ;
	cout << _mag " ]\n\n" _reset ;

}


void	storyline_2(void)
{
	cout << _yellow "\n[ Here's Luke. Luke is different... ]\n";
	cout << "[ While Matthew is a vampire, Luke is a ghost. ";
	cout << "...A real one. ]\n" _reset ;
	cout << _mag "[ Luke is created on the ";
	cout << _red "\"Heap\"" _reset ;
	cout << _mag " ]\n[ ie. built by using the ";
	cout << _red _ital "\"new\"" _reset ;
	cout << _mag " keyword ]\n\n" _reset ;
}


void	storyline_3(void)
{
	cout << _yellow "\n[ Paul is born... ";
	cout << "and dead almost instantly. ]\n\n" _reset;
}


void	storyline_4(void)
{
	cout << _yellow "\n[ Before we go, let's ";
	cout << "KILL Luke. ]\n[ Just because he is the ";
	cout << _ital _red "heap " _reset << _yellow "guy. ]\n";
	cout << "[ ...But we didn't kill Matthew. ]\n\n" _reset;
}

