/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                          xD               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void    display_file(char *s);
void    display_copy(void);
void    msg(char *s, int n);
int     len(char *s);

int     main(int argc, char **argv)
{
    int     i;

    if (argc == 1)
        display_copy();
    i = 1;
    while (i < argc)
    {
        display_file(argv[i]);
        i++;
    }
    return (0);
}

//

void    display_file(char *filename)
{
    int     fd;
    char    c;
    
    fd = open(filename, O_RDWR);
    if (fd < 0)
    {
        msg(filename, errno);
        return ;
    }
    while (read(fd, &c, 1))
        write(1, &c, 1);
    close(fd);
}

void    display_copy(void)
{
    char    c;

    while (read(STDIN_FILENO, &c, 1))
        write(1, &c, 1);
}

void    msg(char *arg, int n)
{
    char    *msg_not_found;
    char    *msg_try_again;
    char    *msg_directory;
    
    msg_not_found = "No such file or directory\n";
    msg_directory = "Is a directory\n";
    msg_try_again = "Try again\n";
    write(2, "cat: ", 5);
    write(2, arg, len(arg));
    write(2, ": ", 2);
    if (n == 2)
        write(2, msg_not_found, len(msg_not_found));
    else if (n == 21)
        write(2, msg_directory, len(msg_directory));
    else
        write(2, msg_try_again, len(msg_try_again));
}

int     len(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
