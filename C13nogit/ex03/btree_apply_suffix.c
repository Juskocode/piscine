/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:23:31 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 20:35:59 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return ;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	(*applyf)(root->item);
}
/*
#include <stdio.h>
#include <stdint.h>
void print_item(void *item) {
    printf("%d\n", (int)(intptr_t)item);
}

int main(void)
{
    t_btree *node1 = btree_create_node((void *)1);
    t_btree *node2 = btree_create_node((void *)2);
    t_btree *node3 = btree_create_node((void *)3);

    node1->left = node2;
    node1->right = node3;

    printf("Applying btree_apply_suffix:\n");
    btree_apply_suffix(node1, &print_item);

    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
