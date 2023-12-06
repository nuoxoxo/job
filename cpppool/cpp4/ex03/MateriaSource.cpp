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

#include "MateriaSource.hpp"
#include "CPP04X03.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaDefault.hpp"

MateriaSource::MateriaSource()
{
	size_t	i;

	i = -1;
	while (++i < MAXMAT)
		m_source[i] = 0;
}

MateriaSource::~MateriaSource()
{
	size_t	i;

	i = -1;
	while (++i < MAXMAT)
	{
		if (!m_source[i])
			continue ;
		delete	m_source[i];
		m_source[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource & src)
{
	size_t	i;

	i = -1;
	while (++i < MAXMAT)
	{
		if (!src.m_source[i])
			continue ;
		// m_source[i] = src.m_source[i];
		m_source[i] = src.m_source[i]->clone();
	}
}

MateriaSource & MateriaSource::operator = (const MateriaSource & src)
{
	size_t	i;

	if (this == & src)
		return (*this);
	i = -1;
	while (++i < MAXMAT)
	{
		if (m_source[i])
			delete	m_source[i];
		if (!src.m_source[i])
			continue ;
		m_source[i] = src.m_source[i]->clone();
	}
	return (*this);
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	size_t	i;

	i = -1;
	while (++i < MAXMAT)
	{
		if (m_source[i] && type == m_source[i]->getType())
			return (m_source[i]->clone());
	}
	if (type == "ice")
		return (new Ice());
	if (type == "cure")
		return (new Cure());
	// return (0);
	return (new MateriaDefault());
}

void	MateriaSource::learnMateria(AMateria * ma)
{
	size_t	i;

	if (!ma)
	{
		std::cout
		<< "nothing is equiped " LOWKEY "(tried to equip "
		<< ma << ") \n" RESET;
		return ;
	}
	i = -1;
	while (++i < MAXMAT)
	{
		if (m_source[i])
			continue ;
		m_source[i] = ma;
		return ;
	}
	delete	ma;
	std::cout << "Inventory is full! \n";
}



