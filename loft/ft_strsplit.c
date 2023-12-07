/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *fill_row(char *row, char const *s, int index, int offset);
int     get_offset(char const *s, int index, char sep);
int     get_size(char const *s, char sep);
int     is_sep(char const c, char sep);

char    **ft_strsplit(char const *s, char sep)
{
        char    **grid;
        int     offset;
        int     size;
        int     i;
        int     j;

        size = get_size(s, sep);
        grid = (char **) malloc(sizeof(char *) * (size + 1));
        if (!grid)
            return NULL;
        i = -1;
        j = -1;
        while (++i < size)
        {
            while (s[++j])
            {
                if (s[j] && !is_sep(s[j], sep))
                {
                    offset = get_offset(s, j, sep);
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

        row = (char *) malloc(sizeof(char) * (offset + 1));
        if (!row)
            return NULL;
        i = -1;
        while (++i < offset)
            row[i] = s[index + i];
        row[i] = 0;
        return (row);
}

int     get_size(char const *s, char sep)
{
        int     offset;
        int     size;
        int     i;

        if (!s)
            return (0);
        size = 0;
        i = 0;
        while (s[++i])
        {
            while (s[i] && is_sep(s[i], sep))
                i++;
            while (s[i] && !is_sep(s[i], sep))
            {
                size += 1;
                offset = get_offset(s, i, sep);
                i += offset;
                break;
            }
            if (!s[i])
                break;
        }
        return (size);
}

int     get_offset(char const *s, int index, char sep)
{
        int     size;
        int     i;
        
        size = 0;
        i = index - 1;
        while (s[++i] && !is_sep(s[i], sep))
            size++;
        return (size);
}

int     is_sep(char const c, char sep)
{
        if (c == sep)
            return (1);
        return (0);
}

/*

// DRIVE

#include "ft_isprint.c"
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
            int     max = 256, i = 0;
            char    s[max], c;
            char    **grid;

            fflush(stdin);
            ft_putstr("Enter separator  : ");
            c = getchar();
            if (!ft_isprint(c)) c = 32;
            fflush(stdin);
            ft_putstr("Enter string     : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            grid = ft_strsplit(s, c);
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
