/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                  :D              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int     len(char *s);
void    msg(int n);

int     main(int argc, char **argv)
{
    char    *name;
    int     fd;
    char    c;
    
    if (argc == 1)
    {
        msg(1);
        return (0);
    }
    if (argc > 2)
    {
        msg(2);
        return (0);
    }
    name = argv[1];
    fd = open(name, O_RDONLY);
    if (fd < 0)
    {
        return (0);
    }
    while (read(fd, &c, 1))
        write(1, &c, 1);
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

void    msg(int n)
{
    char    *msg1, *msg2;
    
    msg1 = "File name missing.\n";
    msg2 = "Too many argument.\n";
    if (n == 1)
    {
        write(2, &msg1, len(msg1));
        }
    if (n == 2)
    {
        write(2, &msg2, len(msg2));
    }
}

int     len(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
