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

#include "Cure.hpp"


// Canon


Cure::Cure() : AMateria("cure") {} // XXX inherits AMT
Cure::~Cure() {}


Cure::Cure(const Cure & copy)
{
	* this = copy;
}


Cure & Cure::operator = (const Cure & dummy)
{
	m_type = dummy.m_type;
	return *this;
}


// methods

void	Cure::use(ICharacter & dummy) const
{
	std::cout << YELL "* heals " << dummy.getName() << "'s wounds * \n" RESET;
}

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
}

