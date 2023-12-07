/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_count_if(char **grid, int(*f)(char *))
{
        int     counter;
        int     i;

        i = 0;
        counter = 0;
        while (grid[i])
        {
            if (f(grid[i]) == 1)
                counter++;
            i++;
        }
        return (counter);
}

/*

//      DRIVE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int     F(char *s);
char    **ft_strsplit_by_whitesp(char const *s);
char    *fill_row(char *row, char const *s, int i, int offset);
int     get_next_size(char const *s, int i);
int     get_full_size(char const *s);
int     is_wsp(char const c);

#define OUT printf("\n(ctrl + c to quit)\n--\n")

int     main(void)
{
        while (1)
        {
            int     i = 0;
            int     max = 1024;
            char    s[max];
            char    **grid;

            fflush(stdin);
            printf("\nEnter string (with some whitespaces in it): \n");
            fgets(s, max, stdin);
            s[ strlen(s) - 1 ] = 0;
            grid = ft_strsplit_by_whitesp(s);
            printf("\nYou have entered all these words: \n--\n");
            while (grid[i]) printf("%s\n", grid[i++]);
            printf("--\n");
            printf("\n%i words are longer than 4.", ft_count_if(grid, &F));
            OUT;
        }
}

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

int     F(char *s)
{
        int     max;

        max = 4;
        if (s && ( int ) strlen(s) > max) return (1);
        return (0);
}

*/
