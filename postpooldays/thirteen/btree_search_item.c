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

void    *btree_search_item
(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
        void    *p;

        if (!root)  return (NULL);
        p = btree_search_item(root->left, data_ref, cmpf);
        if (p)      return (p);
        if (!((*cmpf)(root->item, data_ref)))   return (root->item);
        p = btree_search_item(root->right, data_ref, cmpf);
        if (p)      return (p);
        return (NULL);
}

/*

//  DRIVE

#include <string.h>
#include <stdio.h>

t_btree     *btree_create_node(void *item);
int         void_cmp(void *x, void *y);
void        sep(void);

int     main(void)
{
        const int   max = 64;
        char        s1[max], s2[max], s3[max], target[max];
        t_btree     *node_root, *node_left, *node_right, *outcome;

        while (1)
        {
            printf("Define yout root : ");
            fgets(s1, max, stdin);
            
            s1[strlen(s1) - 1] = 0;
            node_root = btree_create_node(s1);
            
            printf("Enter root's left : ");
            fgets(s2, max, stdin);
            s2[strlen(s2) - 1] = 0;
            node_left = btree_create_node(s2);
            node_root->left = node_left;

            printf("Enter root's right : ");
            fgets(s3, max, stdin);
            s3[strlen(s3) - 1] = 0;
            node_right = btree_create_node(s3);
            node_root->right = node_right;
            
            sep();
            printf("Target : ");
            fgets(target, max, stdin);
            target[strlen(target) - 1] = 0;
            outcome = btree_search_item(node_root, target, &void_cmp);
            printf("Found : %s\n", (char *) outcome);
            sep();
            
            memset(s3, 0, max);
            memset(s1, 0, max);
            memset(s2, 0, max);
            memset(target, 0, max);
            fflush(stdin);
        }

        return (0);
}

//

t_btree     *btree_create_node(void *item)
{
            t_btree     *node;

            node = (t_btree *) malloc(sizeof (t_btree));
            if (!node)  return (NULL);
            node->left = NULL;
            node->right = NULL;
            node->item = item;
            return (node);
}

int         void_cmp(void *x, void *y)
{
            char    *s1 = (char *) x;
            char    *s2 = (char *) y;
            int     i = 0;

            while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
            return (s1[i] - s2[i]);
}

void        sep(void)
{
            printf("--\n");
}

*/
