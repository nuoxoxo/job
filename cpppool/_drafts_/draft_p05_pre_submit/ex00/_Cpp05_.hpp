/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _Cpp05_.hpp                                        :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By: nxu <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nxu               ...    :::             */
/*   Updated: 2023/01/16 14:31:58 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CPP05__HPP
# define _CPP05__HPP

# include "iostream"
# include "string"


void	print_canon(const std::string, const std::string);
void	print_ending(int);
void	print_ending(void);
void	print_ending(std::string &);
void	print_ending(int, const std::string);


//	colors

# define ITAL	"\033[3m"
# define LOWKEY	"\033[0;2m"
# define WHITE	"\033[1;37m"
# define CYAN	"\033[0;36m"
# define YELL	"\033[0;33m"
# define GREEN	"\033[0;32m"
# define RED	"\033[0;31m"
# define MAG	"\033[0;35m"

# define RESET	"\033[0;0m"


//	formatting

# define called " called\n"
# define inside "\ninside "
# define nl2 " \n\n"
# define nl " \n"

#endif


