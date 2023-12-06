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

#ifndef CAT_HPP
# define CAT_HPP

# include "iostream"
# include "string"
# include "cstdlib" // rand

# include "Animal.hpp"
# include "Brain.hpp"


class Cat : public Animal // note the `public` keyword
{

private:
	Brain	*m_brain;

public:
	// canon
	Cat();
	Cat(const Cat &);
	Cat & operator = (const Cat &);
	~Cat();
	
	// method
	void	makeSound() const;

};


#endif

