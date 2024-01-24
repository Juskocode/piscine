/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:47:32 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 00:47:15 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item,
int (*cmpf)(void *, void *))
{
	t_btree	*it;

	if (!*root || !root || !item)
	{
		if (root && item)
			*root = btree_create_node(item);
		return ;
	}
	it = *root;
	if ((*cmpf)(item, (*root)->item) > 0)
	{
		if (it->right)
			btree_insert_data(&it->right, item, cmpf);
		else
			it->right = btree_create_node(item);
	}
	else
	{
		if (it->left)
			btree_insert_data(&it->left, item, cmpf);
		else
			it->left = btree_create_node(item);
	}
}
/*
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if(!root)
		return ;
	(*applyf)(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

#include <stdio.h>
#include <stdint.h>

int compare_int(void *a, void *b) {
    return (*(int *)a - *(int *)b);
}

void print_item(void *item) {
    printf("%d\n", (int)(intptr_t)item);
}

int main(void)
{
    t_btree *root = NULL;

    int values[] = {3, 1, 5, 2, 4};
    int i, n = sizeof(values) / sizeof(values[0]);

    for (i = 0; i < n; ++i) {
        btree_insert_data(&root, &values[i], &compare_int);
    }

    btree_apply_prefix(root, &print_item);

    return 0;
}
*/
