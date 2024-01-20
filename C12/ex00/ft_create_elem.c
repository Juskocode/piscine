/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:08:11 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:18:33 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node)
	{
		new_node->next = NULL;
		new_node->data = data;
	}
	return (new_node);
}
/*
#include <stdio.h>

int main(void)
{
    int data_value = 42;
    t_list *new_node = ft_create_elem(&data_value);

    if (new_node)
    {
        printf("Element created!\n");
        printf("Data: %d\n", *((int *)(new_node->data)));
    }
    else
    {
        printf("Error creating element.\n");
    }

    free(new_node);

    return 0;
}
*/
