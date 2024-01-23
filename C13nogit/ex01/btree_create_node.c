/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:34:02 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 18:56:21 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*new_node;

	new_node = malloc(sizeof(t_btree));
	if (new_node)
	{
		new_node->left = NULL;
		new_node->right = NULL;
		new_node->item = item;
	}
	return (new_node);
}
/*
#include <stdio.h>
#include <stdint.h>
int main(void)
{
    // Creating nodes with integer values for testing
    t_btree *node1 = btree_create_node((void *)1);
    t_btree *node2 = btree_create_node((void *)2);
    t_btree *node3 = btree_create_node((void *)3);

    // Linking nodes to form a simple binary tree
    node1->left = node2;
    node1->right = node3;

    // Displaying the values of the nodes
    printf("Node 1 item: %d\n",(int)(intptr_t)node1->item);
    printf("Node 2 item: %d\n",(int)(intptr_t)node2->item);
    printf("Node 3 item: %d\n", (int)(intptr_t)node3->item);

    // Freeing allocated memory for the nodes
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
