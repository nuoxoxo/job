/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ( s1[i] && s2[i] && s1[i] == s2[i] )
            i++;
	return ( s1[i] - s2[i] );
}

/*

//  DRIVE

#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define OUT     printf("\n(ctrl + c to quit)\n--\n")
#define ENDL    printf("\n")
#define LOAD    loading()

void    loading(void);

int	main(void)
{
        while (1)
        {
            const int   max = 512;
            char        s1[max];
            char        s2[max];

            printf("Enter s1 : ");
            fgets(s1, max, stdin);
            printf("Enter s2 : ");
            fgets(s2, max, stdin);
            LOAD;
            printf("\nlibft result  : ");
            printf("%d", ft_strcmp(s1, s2));
            printf("\nstd   result  : ");
            printf("%d", strcmp(s1, s2));
            OUT;
            fflush(stdin);
        }

        return (0);
}

void    loading(void)
{
        int     rand;

        rand = 1000 * 32;
        printf("loading");
        for (int i = 12; i > 0; i--)
        {
            usleep(rand);
            printf(".");
        }
        ENDL;
}

*/
