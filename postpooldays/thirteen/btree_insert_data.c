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

t_btree *btree_create_node(void *item);

void    btree_insert_data\
        (t_btree **root, void *item, int (*cmpf)(void *, void *))
{
        if (!root || !item) return ;
        if (!(*root))
        {
            *root = btree_create_node(item);
            return ;
        }
        if ((*cmpf) (item, (*root)->item) < 0)
            btree_insert_data(&(*root)->left, item, cmpf);
        else
            btree_insert_data(&(*root)->right, item, cmpf);
}

t_btree *btree_create_node(void *item)
{
        t_btree     *node;

        node = (t_btree *) malloc(sizeof (t_btree));
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

int     void_cmp(void *s1, void *s2);

int     main(void)
{
        const int   max = 64;
        char        root[max];
        char        item[max];
        t_btree     *node;

        while (1)
        {
            printf("Enter root : ");
            fgets(root, max, stdin);
            printf("Enter item : ");
            fgets(item, max, stdin);

            root[strlen(root) - 1] = '\0';
            item[strlen(item) - 1] = '\0';
            
            node = btree_create_node(root);
            btree_insert_data(&node, item, &void_cmp);
            
            printf("\n%s\n", (char *) (node->item));
            printf("│\n├─── left ──> ");
            if (node->left) printf("%s\n", (char *) node->left->item);
            else printf("(null)\n");
            printf("│\n└─── right ─> ");
            if (node->right) printf("%s\n", (char *) node->right->item);
            else printf("(null)\n");
            printf("--\n");
            
            memset(item, 0, max);
            memset(root, 0, max);
            fflush(stdin);
        }
        return (0);
}

int     void_cmp(void *a, void *b)
{
        char    *s1 = (char *) a;
        char    *s2 = (char *) b;
        int     i = 0;

        while (s1[i] && s2[i] && s1[i] == s2[i]) i++;
        return (s1[i] - s2[i]);
}

*/
