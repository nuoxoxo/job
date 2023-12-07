/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_advanced.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/08/19 __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     is_num(char c);
int     is_wsp(char c);

int	ft_atoi_advanced(const char *str)
{
	int	sign;
	int	tt;
	int	i;

	sign = 1;
	tt = 0;
	i = 0;
	while (is_wsp(str[i]) == 1)
            i++;
	while (str[i] == '-' || str[i] == '+')
        {
	    if (str[i] == '-')
    		sign *= -1;
	    i++;
	}
	while (is_num(str[i]) == 1)
	{
            tt = tt * 10 + str[i] - '0';
            i++;
	}
	return (sign * tt);
}

int	is_num(char c)
{
	if (c <= '9' && c >= '0')
            return (1);
	return (0);
}

int	is_wsp(char c)
{
	if (c == ' ' || (c < 14 && c > 8))
	    return (1);
	return (0);
}

/*

//  DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define TEST    atoitest()
#define LOAD    loading()

void    atoitest(void);
void    loading(void);

int     main(void)
{
        LOAD;TEST;
        LOAD;
        while (1)
        {
            int     max = 64;
            char    s[max];
            
            ft_putstr("enter a string : ");
            fgets(s, max, stdin);
            LOAD;
            printf("atoi : %d\ntest : %d\n\n", atoi(s), ft_atoi_advanced(s));
            OUT;
            fflush(stdin);
        }
        return (0);
}

void    atoitest(void)
{
        ft_putendl("=== random tests ===\n");
        ft_putendl("test string : \" --+-042a:f545\"");
        printf("atoi : %d\ntest : %d\n\n",
            atoi(" --+-042a:f545"), ft_atoi_advanced(" --+-042a:f545"));
	ft_putendl("test string : \"  \\n  42t4457\"");
	printf("atoi : %d\ntest : %d\n\n",
            atoi("  \n  42t4457"), ft_atoi_advanced("  \n  42t4457"));
        ft_putendl("test string : \\\0 1337");
        printf("atoi : %d\ntest : %d\n\n", 
            atoi("\0 1337"), ft_atoi_advanced("\0 1337"));
        ft_putendl("test string : -0");
        printf("atoi : %d\ntest : %d\n\n",
            atoi("-0"), ft_atoi_advanced("-0"));
        ft_putendl("test string : \" - 1 6 7\"");
        printf("atoi : %d\ntest : %d\n\n",
            atoi(" - 1 6 7"), ft_atoi_advanced(" - 1 6 7"));
        ft_putendl("test string : \"\\t---+2147483648\"");
        printf("atoi : %d\ntest : %d\n\n",
            atoi("\t---+2147483648"), ft_atoi_advanced("\t---+2147483648"));
        ft_putendl("test string : \"\\v2147483647\"");
        printf("atoi : %d\ntest : %d\n\n", 
            atoi("\v2147483647"), ft_atoi_advanced("\v2147483647"));
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
