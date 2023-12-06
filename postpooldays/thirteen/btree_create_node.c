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

#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
        t_btree     *node;

        node = (t_btree *) malloc(sizeof(t_btree));
        if (!node)  return (NULL);
        node->left = NULL;
        node->right = NULL;
        node->item = item;
        return (node);
}

/*

//  DRIVE

#include <string.h>
#include <stdio.h>

int     main(void)
{
        const int   max = 64;
        t_btree     *node;    
        char        s[max];

        while (1)
        {
            printf("Enter something : ");
            fgets(s, max, stdin);
            node = btree_create_node(s);
            printf("address : %p\n", node->item);
            printf("char *s : %s", (char *)node->item);
            printf("--\n");
            memset(s, 0, max);
            fflush(stdin);
        }
        return (0);
}

*/
