/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   {}.cpp                                             :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/09 14:55:26 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define B_SIZE 100

# include "iostream"
# include "string"
# include "cstdlib" // rand
# include "_Cpp04_.hpp"

class	Brain
{

private:
	std::string	m_idea[B_SIZE];

public:
	// canon
	Brain();
	Brain(const Brain &);
	Brain & operator = (const Brain &);
	~Brain();

	// getter
	
	const std::string	& getIdea(int) const;
	
	void	setIdea(int, std::string);
	void	makeSound() const;

};

#endif
