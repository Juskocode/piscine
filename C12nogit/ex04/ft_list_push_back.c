/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:07:34 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:24:27 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_last, void *data)
{
	t_list	*it;

	it = *begin_list;
	if (it)
	{
		while (it->next)
			it = it->next;
		it->next = ft_create_elem(data);
		return ;
	}
	*begin_list = ft_create_elem(data);
}
/*
#include <stdio.h>

int main(void)
{
    t_list *list = NULL;

    int data_value1 = 42;
    int data_value2 = 56;

    ft_list_push_back(&list, &data_value1);
    ft_list_push_back(&list, &data_value2);

    t_list *current = list;
    while (current)
    {
        printf("%d ", *((int *)(current->data)));
        current = current->next;
    }
    printf("\n");

    // Assuming ft_list_push_back takes care of freeing memory
    // If not, free the list manually.

    return 0;
}
*/
