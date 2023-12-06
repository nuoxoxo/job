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

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# define MAXMAT 4

class	MateriaSource : public IMateriaSource
{

private:

	AMateria	* m_source[ MAXMAT ];

public:

	// Canon
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &);
	MateriaSource & operator = (const MateriaSource &);

	// Methods
	AMateria	*createMateria(std::string const &);
	void		learnMateria(AMateria *);

};

#endif
