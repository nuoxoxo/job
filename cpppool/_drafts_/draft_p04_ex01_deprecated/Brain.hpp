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

# include "iostream"
# include "string"

# define N 100

class Brain
{

private:
	std::string	m_idea[N];

public:
	// canon
	Brain();
	~Brain();
	Brain(const Brain &);
	Brain & operator = (const Brain &);

	// what to do with the idea[100] (?)
};


#endif

