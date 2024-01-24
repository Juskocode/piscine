/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:23:35 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:19:53 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*to_add;

	if (*begin_list)
	{
		to_add = ft_create_element(data);
		to_add->next = *begin_list;
		*begin_list = to_add;
		return ;
	}
	*begin_list = ft_create_element(data);
}
/*
#include <stdio.h>

int main(void)
{
    t_list *list = NULL;

    int data_value1 = 42;
    int data_value2 = 56;

    ft_list_push_front(&list, &data_value1);
    ft_list_push_front(&list, &data_value2);

    printf("Updated list:\n");
    t_list *current = list;
    while (current)
    {
        printf("%d ", *((int *)(current->data)));
        current = current->next;
    }
    printf("\n");

    free(list);

    return 0;
}
*/
