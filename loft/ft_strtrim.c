/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  count_trailing_whitespace(char const *s);
size_t  count_leading_whitespace(char const *s);

char    *ft_strtrim(char const *s)
{
        char    *res;
        size_t  head;
        size_t  tail;
        size_t  len;
        size_t  i;

        if (!s)
            return (NULL);
        len = ft_strlen(s);
        head = count_leading_whitespace(s);
        tail = count_trailing_whitespace(s);
        if (len == head + tail)
            return (NULL);
        //res = (char *) malloc(sizeof(char) * (head + tail));	// wrong
        res = (char *) malloc(sizeof(char) * (len - head - tail));
	if (!res)
            return NULL;
        i = 0;
        tail = len - tail - 1;
        while (head <= tail)
            res[i++] = s[head++];
        res[i] = 0;
        return (res);
}

size_t  count_trailing_whitespace(char const *s)
{
        size_t  len;
        size_t  i;

        len = ft_strlen(s);
        len--;
        i = 0;
        while (s[len - i] == ' ' || s[len - i] == '\n' || s[len - i] == '\t')
            i++;
        return (i);
}

size_t  count_leading_whitespace(char const *s)
{
        size_t  len;
        size_t  i;

        len = ft_strlen(s);
        i = 0;
        while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
            i++;
        return (i);
}


//      DRIVE

#include "ft_strlen.c"
#include "ft_putstr.c"
#include "ft_putendl.c"
#include "stdio.h"

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    putendl_quote(char *s);
void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 64;
            char    s[max];

            fflush(stdin);
            ft_putstr("enter string : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            LOAD;
            ft_putstr("original : ");
            putendl_quote(s);
            ft_putstr("trimmed  : ");
            putendl_quote(ft_strtrim(s));
            OUT;
        }
        return (0);
}

void    putendl_quote(char *s)
{
        ft_putstr("\"");
        ft_putstr(s);
        ft_putstr("\"");
        ft_putendl("");
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

