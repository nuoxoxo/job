/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int     main(int ac, char **av)
{
        int     offset;
        int     i;
        
        offset = 0;
        i = verify_argv(ac, av);
        if (!i)
            return (0);
        if (i == 3)
        {
            offset = atoi_easy(av[2]);
            if (av[2][0] != '+')
            {
                if (offset < 0) offset *= -1;
                while (av[i])
                {
                    display_c_tail(av[i], offset, i, ac); 
                    i++;
                }
                return (0);
            }
            while (av[i])
            {
                display_c_head(av[i], offset, i, ac);
                i++;
            }
            return (0);
        }
        while (av[i])
        {
            display_default(av[i], i, ac);
            i++;
        }
        return (0);
}
