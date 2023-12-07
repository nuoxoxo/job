/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *fill_row(char *row, char const *s, int index, int offset);
int     get_offset(char const *s, int index, char *charset);
int     get_size(char const *s, char *charser);
int     is_sep(char const c, char *s);

char    **ft_strsplit_by_charset(char const *s, char *charset)
{
        char    **grid;
        int     offset;
        int     size;
        int     i;
        int     j;

        size = get_size(s, charset);
        grid = (char **) malloc(sizeof(char *) * (size + 1));
        if (!grid)
            return NULL;
        i = -1;
        j = -1;
        while (++i < size)
        {
            while (s[++j])
            {
                if (s[j] && !is_sep(s[j], charset))
                {
                    offset = get_offset(s, j, charset);
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

int     get_size(char const *s, char *charset)
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
            while (s[i] && is_sep(s[i], charset))
                i++;
            while (s[i] && !is_sep(s[i], charset))
            {
                size += 1;
                offset = get_offset(s, i, charset);
                i += offset;
                break;
            }
            if (!s[i])
                break;
        }
        return (size);
}

int     get_offset(char const *s, int index, char *charset)
{
        int     size;
        int     i;
        
        size = 0;
        i = index - 1;
        while (s[++i] && !is_sep(s[i], charset))
            size++;
        return (size);
}

int     is_sep(char const c, char *s)
{
        int     i;

        i = -1;
        while (s[++i])
        {
            if (c == s[i])
                return (1);
        }
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
            int     max = 256, i = 0;
            char    s[max], c[max];
            char    **grid;

            fflush(stdin);
            ft_putstr("Enter string     : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            fflush(stdin);
            ft_putstr("Enter charset    : ");
            fgets(c, max, stdin);
            c[ ft_strlen(c) - 1 ] = 0;
            grid = ft_strsplit_by_charset(s, c);
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
