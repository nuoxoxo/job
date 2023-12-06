/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include "iostream"

void	    lowercase_str(std::string &);
void        lowercase_char(char &) ;

void	    parse_input(std::string &);
bool        isnumeric(std::string &);
std::string get_input(std::string const);

#endif
