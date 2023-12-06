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

#ifndef CURE_HPP
# define CURE_HPP

# include "iostream"
# include "AMateria.hpp"


class	Cure : public AMateria
{

public:

	// canon
	Cure();
	~Cure(); // TODO no virtual
	Cure(const Cure &);
	Cure & operator = (const Cure &);

	AMateria	*clone() const;
	void		use(ICharacter &) const;

};


#endif
