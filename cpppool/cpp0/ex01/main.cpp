/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "Phonebook.hpp"
#include "Contact.hpp"
#include "Utils.hpp"

int main()
{
    std::string input;
    Phonebook P; 
    int index = 1;

    std::cout << DELIM << NL2 << ONAIR << USAGE << SKIP_PROMPT;
    while (!std::cin.eof())
    {
        std::cout << "➜ ";
        std::getline(std::cin, input);
        parse_input(input);
        if (input == "add")
        {
            Contact this_guy;
            index = index > PHONEBOOK_THICKNESS ? index : 1;
            if (! this_guy.add())
                break;
            P.append(this_guy);
            index++;
        }
        else if (input == "search")
        {
            if (! P.search(P))
                break;
        }
        else if (input == "exit")
        {
            std::cout << "➜ \n➜ All contacts will be lost forever. \n";
			std::cout << "➜ Goodbye and have a nice day." << SKIP_PROMPT;
			break ;
        }
        else
        {
            continue ;
        }
    }
    return (0);
}

//

