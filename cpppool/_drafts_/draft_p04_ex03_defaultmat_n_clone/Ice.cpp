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
/*                           Abstrac Class (AClass)                           */
/*                             Interface (IClass)                             */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#include "Ice.hpp"


// Canon


Ice::Ice() : AMateria("ice") {} // XXX inherits AMT
Ice::~Ice() {}


Ice::Ice(const Ice & copy)
{
	* this = copy;
}


Ice & Ice::operator = (const Ice & dummy)
{
	m_type = dummy.m_type;
	return *this;
}


// methods

void	Ice::use(ICharacter & dummy) const
{
	std::cout << CYAN "* shoots an ice bolt at " << dummy.getName() << " * \n" RESET;
}


AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}


