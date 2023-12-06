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

int     btree_level_count(t_btree *root)
{
        int     L, R;

        if (!root)          return (0);
        L = R = 1;
        if (root->left)     L = btree_level_count(root->left) + 1;
        if (root->right)    R = btree_level_count(root->right) + 1;
        if (L < R)          return (R);
        else                return (L);
}

/*

//  DRIVE

#include <stdio.h>

t_btree     *btree_create_node(void *item);
void        space_x1(void);
void        space_x2(void);
void        put_tree(t_btree *node);
void        deallocate (t_btree *node);

int     main(void)
{ 
        char        *a, *b, *c, *d, *e, *f, *g;
        t_btree     *node;

        a = "a";
        b = "b";
        c = "c";
        d = "d";
        e = "e";
        f = "f";
        g = "g";
        node = btree_create_node(&a);
        node->left = btree_create_node(&b);
        node->right = btree_create_node(&c);
        node->right->left = btree_create_node(&d);
        node->right->right = btree_create_node(&e);
        node->right->right->left = btree_create_node(&f);
        node->right->right->right = btree_create_node(&g);
        put_tree(node);
        printf("Level count : ");
        printf("%i\n", btree_level_count(node));

        return (0);
}

//

void        deallocate (t_btree *node)
{
            if (!node)  return ;
            deallocate(node->left);
            deallocate(node->right);
            free(node);
}

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

void        put_tree(t_btree *node)
{
            printf("%p\n", node);
            printf("│\n");
            printf("├─── L ─── %p\n", node->left);
            printf("│\n");
            printf("└─── R ─── %p\n", node->right);
            space_x1();
            printf("├─── L ─── %p\n", node->right->left);
            space_x1();
            printf("└─── R ─── %p\n", node->right->right);
            space_x2();
            printf("├─── L ─── %p\n", node->right->right->left);
            space_x2();
            printf("└─── R ─── %p\n", node->right->right->right);
}

void        space_x1(void)
{
            printf("           │\n           ");
}

void        space_x2(void)
{
            printf("                      │\n                      ");
}

*/
