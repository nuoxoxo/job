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

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "iostream"
# include "string"
# include "cstdlib" // rand
# include "_Cpp04_.hpp"

class	Animal
{

protected: // Inheritance
	std::string	m_type;

public:
	// canon
	Animal();
	Animal(const Animal &);
	Animal & operator = (const Animal &);

	virtual	~Animal(); // Polymorphism

	// param constructor
	Animal(std::string);

	// getter
	std::string	getType() const;

	// method
	virtual void	makeSound() const; // Polymorphism

	// notes
	// why virtual destructor - q.v. x00
	// why virtual functions - q.v. x00
};


#endif
