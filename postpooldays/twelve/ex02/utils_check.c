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

int     verify_argv(int ac, char **av)
{
        if (ac < 2) display_stdout();
        if (av[1][0] == '-')
        {
            if (av[1][1] == '-' && !av[1][2])
                display_stdout();
            if (av[1][1] == 'c' && av[2] && check_if_only_num(av[2]) && !av[3])
            {
                display_stdout();
            }
            return verify_argv_minus(av);
        }
        return (1);
}

int     verify_argv_minus(char **av)
{
        if (!av[1][1])
        {
            msg(av[1], 0);
            return (0);
        }
        if (av[1][1] != 'c')
        {
            msg(av[1], 1);
            return (0);
        }
        if (av[1][1] == 'c')
        {
            if (!av[2])
            {
                msg(av[1], 2);
                return (0);
            }
            if (!check_if_only_num(av[2]))
            {
                msg(av[2], 3);
                return (0);
            }
            return (3);
        }
        return (1);
}

int     count_size_of_file(char *filename, int mode)
{
        char    c;
        int     fd;
        int     size;

        size = 0;
        fd = open(filename, O_RDONLY);
        if (mode == 0)
        {
            while (read(fd, &c, 1))
            {
                if (c == 0 || c == '\n')
                    size++;
            }
        }
        else if (mode == 1)
        {
            while (read(fd, &c, 1)) 
                size++;
        }
        close(fd);
        return (size);
}

int     check_if_only_num(char *s)
{
        int     i;

        i = 0;
        if (s[i] == '-' || s[i] == '+')
            i += 1;
        while (s[i])
        {
            if (s[i] < 48 || s[i] > 57) return (0);
            i++;
        }
        return (1);
}
