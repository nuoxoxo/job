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

#ifndef MATERIADEFAULT_HPP
# define MATERIADEFAULT_HPP

# include "iostream"
# include "AMateria.hpp"


class	MateriaDefault : public AMateria
{

public:

	// canon
	MateriaDefault();
	~MateriaDefault();
	MateriaDefault(const MateriaDefault &);
	MateriaDefault & operator = (const MateriaDefault &);

	AMateria	*clone() const;
	void		use(ICharacter &) const;

};


#endif
