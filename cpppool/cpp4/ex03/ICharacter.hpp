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
/*                             Interface (IClass)                             */
/*                           Abstrac Class (AClass)                           */
/*                                                                            */
/*                                                                            */
/* *********************  ʕ • ᴥ•ʔ  mode: todo  (⊙. ⊙ )  ********************* */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "iostream"
# include "CPP04X03.hpp"
# include "AMateria.hpp"

class	AMateria;

class	ICharacter
{

public:

	virtual	~ICharacter() {}

	virtual	std::string const & getName() const = 0;

	virtual	void	use(int, ICharacter & )	= 0;
	virtual void	equip(AMateria * ) = 0;
	virtual void	unequip(int) = 0;
};

#endif
