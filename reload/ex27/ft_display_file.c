/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char    *name;
    int     fd;
    char    c;

    if (argc == 1)
    {
        write(2, "File name missing.\n", 20);
        return (0);
    }
    if (argc > 2)
    {
        write(2, "Too many arguments.\n", 21);
        return (0);
    }
    name = argv[1];
    fd = open(name, O_RDONLY);
    if (fd < 0)
        return (0);
    while (read(fd, &c, 1))
    {
        write(1, &c, 1);
    }
    close(fd);
}

// open() returns a small, nonnegative integer
// -1 if an error occurred

// read() returns the number of bytes read on success
// 0 at end of file
// -1 on error, and errno is set appropriately

// read(int fildes, void *buf, size_t count);
// int open(const char *path, int flags ie. modes);
// int close(int fd);
