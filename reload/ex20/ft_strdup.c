/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 22:27:31 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/19 19:54:31 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*

// DRIVE

#include <stdio.h>

char    *ft_strdup(char *truc);

int main()
{
	char x[] = "more news from nowhere"; printf("1.\n%s\n", x);
	char *y = ft_strdup(x); printf("%s\n\n", y);
	char a[] = "**?>>>nowhere, now here"; printf("2.\n%s\n", a);
	char *b = ft_strdup(a); printf("%s\n\n", b);
}

*/

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*des;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	des = malloc(sizeof(char) * (i + 1));
	ptr = des;
	if (!des)
		return (NULL);
	while (*src)
		*des++ = *src++;
	*des = '\0';
	return (ptr);
}
