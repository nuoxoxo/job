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

#include "MateriaDefault.hpp"


// Canon


MateriaDefault::MateriaDefault() : AMateria("(unknown materia)") {} // XXX inherits AMT
MateriaDefault::~MateriaDefault() {}


MateriaDefault::MateriaDefault(const MateriaDefault & copy)
{
	* this = copy;
}


MateriaDefault & MateriaDefault::operator = (const MateriaDefault & dummy)
{
	m_type = dummy.m_type;
	return *this;
}


// methods

void	MateriaDefault::use(ICharacter & dummy) const
{
	std::cout << "* uses " << m_type << " on " << dummy.getName() << " \n";
}

AMateria	*MateriaDefault::clone() const
{
	return (new MateriaDefault(*this));
}

