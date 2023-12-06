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

#ifndef DOG_HPP
# define DOG_HPP

# include "iostream"
# include "string"
# include "cstdlib" // rand
# include "Animal.hpp"


class Dog : public Animal // note the `public` keyword
{

//protected:
//	std::string	m_type;

public:
	// canon
	Dog();
	~Dog();
	Dog(const Dog &);
	Dog & operator = (const Dog &);
	
	// overload
	// Dog(std::string); // pas de dog('dog_name')
	// getter
	// std::string	getType() const; // pas de gettype pour chiens

	// method
	void	makeSound() const;

};


#endif

