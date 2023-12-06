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

#ifndef ICE_HPP
# define ICE_HPP

# include "iostream"
# include "AMateria.hpp"


class	Ice : public AMateria // TODO
{

public:

	// canon
	Ice();
	~Ice(); // TODO no virtual
	Ice(const Ice &);
	Ice & operator = (const Ice &);

	AMateria	*clone() const;
	void		use(ICharacter &) const;

};


#endif
