/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    ... ...         :::     */
/*   By:  nuxu <marvin@42.fr>                       ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuxu              ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuxu             ...   ::::::::.fi       */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

int Contact::add()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string secret;

    while (first_name == "")
        first_name = get_input("Please enter your first name:");
    while (last_name == "")
        last_name = get_input("Please enter your last name:");
    while (nickname == "")
        nickname = get_input("Please enter your nickname:");
    while (phone_number == "" || ! isnumeric(phone_number))
    {
        std::cout << "Numeric values required. \n";
        phone_number = get_input("Please enter your phone number:");
    }
    while (secret == "")
        secret = get_input("Please enter your darkest secret:");
    set_first_name(first_name);
    set_last_name(last_name);
    set_nickname(nickname);
    set_phone(phone_number);
    set_secret(secret);
    return (1);
}
