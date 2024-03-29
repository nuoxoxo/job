/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2022/11/11 14:50:56 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*haystack == '\0')
		return (NULL);
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] && haystack[i + j] == needle[j] \
				&& i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)(haystack + i));
			}
		}
		i++;
	}
	return (NULL);
}

/*

size_t	len_strnstr(char *s);

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = len_strnstr((char *) needle);
	if (!len)
		return ((char *) haystack);
	i = -1;
	while (haystack[++i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < n)
		{
			j++;
			if (j == len)
				return ((char *) &haystack[i]);
		}
	}
	return (0);
}

size_t	len_strnstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

*/

/*

//  DRIVE

#include <string.h>
#include <stdio.h>
//#include "ft_putendl.c"
//#include "ft_putstr.c"

#define OUT     printf("\n(ctrl + c to quit)\n--\n\n")
#define ENDL    printf("\n\n")
#define LOAD    loading()

void    loading(void);

int	main(void)
{
        while (1)
        {
            int     max = 64;
            char    hays[max];
            char    need[max];
            int     n;

            fflush(stdin);
            printf("haystack : ");
            fgets(hays, max, stdin);
            
	    fflush(stdin);
            printf("needle   : ");
            fgets(need, max, stdin);
            
	    fflush(stdin);
            printf("size     : ");
            scanf("%i", &n);
	    hays[ strlen(hays) - 1 ] = 0;
            need[ strlen(need) - 1 ] = 0;
            LOAD;

	    printf("STL  : %s\n", strnstr(hays, need, n));
            printf("Here : %s\n", ft_strnstr(hays, need, n));
            OUT;
        }
}

//

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
