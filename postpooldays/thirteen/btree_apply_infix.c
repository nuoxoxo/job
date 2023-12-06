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

void    btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
        if (!root)  return ;
        btree_apply_infix(root->left, applyf);
        (*applyf) (root->item);
        btree_apply_infix(root->right, applyf);
}

/*

//  DRIVE

#include "btree_create_node.c"
#include <string.h>
#include <stdio.h>

void    putstrlen(void *s);

int     main(void)
{
        const int   max = 64;
        t_btree     *node;
        char        s[max];

        while(1)
        {
            printf("Type a phrase : ");
            fgets(s, max, stdin);
            printf("string length : ");
            node = btree_create_node(s);
            btree_apply_infix(node, &putstrlen);
            printf("--\n");
            memset(s, 0, max);
            fflush(stdin);
        }
        return (0);
}

void    putstrlen(void *s)
{
        int i = strlen((char *) s) - 1;

        printf("%i\n", i);
}

*/
