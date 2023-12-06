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

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "iostream"
# include "AMateria.hpp"
# include "ICharacter.hpp"

# define MAXINV 4

class	Character : public ICharacter
{

private:
	
	Character(); // XXX _ Important _

	std::string	m_name;
	AMateria	*m_inventory[4];

public:

	// canon

	~Character();
	Character(const Character &);
	Character & operator = (const Character &);
	
	// param constr
	Character(std::string);
	// Character(std::string const &);

	// getter
	AMateria		* getMateria(int) const;
	std::string const	& getName() const;


	// methods
	void	use(int, ICharacter & );
	void	equip(AMateria *);
	void	unequip(int);
};

#endif

