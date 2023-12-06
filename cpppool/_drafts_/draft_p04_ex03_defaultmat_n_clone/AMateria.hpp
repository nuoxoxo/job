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

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "iostream"
# include "CPP04X03.hpp"
# include "ICharacter.hpp"

class	AMateria
{

protected:
	
	std::string	m_type;

public:

	// canon
	AMateria();
	virtual	~AMateria();
	AMateria(const AMateria &);
	AMateria & operator = (const AMateria &);
	
	// param constr
	AMateria(std::string const &);
	// AMateria(std::string);

	// getter
	std::string const & getType() const;

	// methods
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &) const = 0;
	// virtual void		use(ICharacter &) const;
};

#endif
