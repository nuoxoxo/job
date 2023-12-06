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
# include "Animal.hpp"


class Dog : public Animal // note the `public` keyword
{

public:

	// canon
	Dog();
	~Dog();
	Dog(const Dog &);
	Dog & operator = (const Dog &);

	// method
	void	makeSound() const;

};


#endif

