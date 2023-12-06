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

void    display_c_head(char *filename, int offset, int i, int ac)
{
        char    c;
        int     fd;
        int     size;
        int     count;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return ;
        }
        if (i > 2 && ac > 3)
        {
            if (i != 3) write(1, "\n", 1);
            display_filename(filename);
        }
        size = count_size_of_file(filename, 1);
        if (size < offset)  offset = size;
        count = 0;
        while (read(fd, &c, 1))
        {
            if (count >= offset - 1)    write(1, &c, 1);
            else
                count++;
        }
        close(fd);
}

void    display_c_tail(char *filename, int offset, int i,int ac)
{
        char    c;
        int     fd;
        int     size;
        int     count;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return ;
        }
        if (ac > 3)
        {
            if (i != 3) write(1, "\n", 1);
            display_filename(filename);
        }
        size = count_size_of_file(filename, 1);
        if (size < offset)  offset = size;
        count = 0;
        while (read(fd, &c, 1))
        {
            if (count >= size - offset) write(1, &c, 1);
            count++;
        }
        close(fd);
}

void    display_default(char *filename, int i, int ac)
{ 
        char    c;
        int     fd;
        int     size;
        int     offset;
        int     count;

        fd = open(filename, O_RDONLY);
        if (fd < 0)
        {
            msg(filename, 0);
            return ;
        }
        if (ac > 2)
        {
            if (i != 1) write(1, "\n", 1);
            display_filename(filename);
        }
        offset = 10;
        size = count_size_of_file(filename, 0);
        if (size < offset)  offset = size;
        count = 0;
        while (read(fd, &c, 1))
        {
            if (count >= size - offset) write(1, &c, 1);
            if (c == '\n' && count <= offset)
                count++;
        }
        close(fd);
}

void    display_filename(char *filename)
{
        write(1, "==> ", 4);
        write(1, filename, len(filename));
        write(1, " <==\n", 5);
}

void    display_stdout(void)
{
        char    c;
        
        while (read(STDIN_FILENO, &c, 1))
            continue;
}
