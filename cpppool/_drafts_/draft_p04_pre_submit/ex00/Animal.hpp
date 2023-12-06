/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/16 15:52:42 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

	virtual	~Animal(); // Polymorphism	// Why virtual destructor -> vide infra

	// param constructor
	Animal(std::string);

	// getter
	std::string	getType() const;

	// method
	virtual void	makeSound() const;	// Polymorphism // Why virtual destructor -> vide infra

};


#endif


/*

> Why virtual destructor ? 

	- because you might potentially delete an instance of a Subclass
through a pointer to the SUperclass

	- also if a Superclass has any virtual function, it should have a virtual destructor

	* Classes not designed to be Superclasses or not designed to be used _polymorphically_
should NOT declare virtual destructors

*//*

> why virtual functions ?

	- ... now we have the option of modifying this function in sub classes

*/
