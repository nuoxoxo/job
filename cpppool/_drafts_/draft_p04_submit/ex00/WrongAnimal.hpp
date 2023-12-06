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

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include "iostream"
# include "string"
# include "_Cpp04_.hpp"

class	WrongAnimal
{

protected:

	std::string	m_type;

public:
	// canon
	WrongAnimal();
	
	WrongAnimal(const WrongAnimal &);
	WrongAnimal & operator = (const WrongAnimal &);
	
	virtual	~WrongAnimal(); // note the `virtual` keyword here
	
	// overload
	WrongAnimal(std::string);

	// getter
	std::string	getType() const;

	// method
	virtual void	makeSound() const; // note the `virtual destructor`

};

#endif
