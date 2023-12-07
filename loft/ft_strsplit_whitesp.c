/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitesp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *fill_row(char *row, char const *s, int i, int offset);
int     get_next_size(char const *s, int i);
int     get_full_size(char const *s);
int     is_wsp(char const c);

char    **ft_strsplit_by_whitesp(char const *s)
{
        char    **grid;
        int     offset;
        int     size;
        int     i;
        int     j;

        size = get_full_size(s);
        if (!(grid = (char **) malloc(sizeof(char *) * (size + 1))))
            return NULL;
        i = -1;
        j = -1;
        while (++i < size)
        {
            while (s[++j])
            {
                if (s[j] && !is_wsp(s[j]))
                {
                    offset = get_next_size(s, j);
                    grid[i] = fill_row(grid[i], s, j, offset);
                    j += offset;
                    break;
                }
            }
        }
        if (!(grid[i] = (char *) malloc(sizeof(char))))
            return NULL;
        grid[i] = 0;
        return (grid);
}

char    *fill_row(char *row, char const *s, int index, int offset)
{
        int     i;

        if (!(row = malloc(sizeof(char) * (offset + 1))))
            return NULL;
        i = 0;
        while (i < offset)
        {
            row[i] = s[index + i];
            i++;
        }
        row[i] = 0;
        return (row);
}


int     get_full_size(char const *s)
{
        int     i;
        int     size;
        int     offset;

        if (!s)
            return 0;
        i = -1;
        size = 0;
        while (s[++i])
        { 
            while (s[i] && is_wsp(s[i]))
                i++;
            while (s[i] && !is_wsp(s[i]))
            {
                size += 1;
                offset = get_next_size(s, i);
                i += offset;
                break ;
            }
            if (!s[i])
                break ;
        }
        return (size);
}

int     get_next_size(char const *s, int index)
{
        int     size;
        int     i;

        size = 0;
        i = index - 1;
        while (s[++i] && !is_wsp(s[i]))
            size++;
        return (size);
}

int     is_wsp(char const c)
{
        if (c == ' ' || (c < 14 && c > 8))
            return 1;
        return (0);
}

/*

// DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strclr.c"
#include "ft_strlen.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 128, i = 0;
            char    **grid;
            char    s[max];

            fflush(stdin);
            ft_putendl("Enter string (with some whitespaces in it): ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            grid = ft_strsplit_by_whitesp(s);
            LOAD;
            while (grid[i]) ft_putendl(grid[i++]);
            OUT;
        }
        return (0);
}

void    loading(void)
{
        int     rand;

        rand = 1000 * 32;
        ft_putstr("loading");
        for (int i = 12; i > 0; i--)
        {
            usleep(rand);
            ft_putstr(".");
        }
        ENDL;
}

*/
