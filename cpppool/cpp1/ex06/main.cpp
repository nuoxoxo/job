/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nuo <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuo               ...    :::             */
/*   Updated: 2023/01/02 15:39:43 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int c, char *v[])
{
	Harl		Kafka;

	if (c ^ 2)
		return (usage(), 0);
	Kafka.complain(std::string(v[1]));
}
