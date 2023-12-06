/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nuo              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

#include "Stream_editor.hpp"

void	usage(void);

int	main(int c, char *v[])
{
	Stream_editor		sed;

	if (c ^ 4)
		return (usage(), 1);
	if (!sed.setup_infile(v[1]))
	{
		std::cout << "err 1 \n";
	}
	if (!sed.replace(v[2], v[3]))
	{
		std::cout << "err 2 \n";
	}

}

void	usage(void)
{
	std::cout << "usage \n";
}
