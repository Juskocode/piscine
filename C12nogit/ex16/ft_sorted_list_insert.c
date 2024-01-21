/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:10:16 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:36:19 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	list_push_back(t_list **begin_with, void *data)
{
	t_list	*tmp;

	if (*begin_with == 0)
	{
		*begin_with = ft_create_elem(data);
		return ;
	}
	tmp = *begin_with;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
}

void	list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*ptr;
	t_list	*ptr2;
	t_list	*next;

	ptr = *begin_list;
	while (ptr)
	{
		ptr2 = *begin_list;
		while (ptr2->next)
		{
			if ((*cmp)(ptr2->data, ptr2->next->data) > 0)
			{
				next = ptr2->data;
				ptr2->data = ptr2->next->data;
				ptr2->next->data = next;
			}
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	list_push_back(begin_list, data);
	list_sort(begin_list, cmp);
}
/*
#include <stdio.h>
#include <stdlib.h>

// Assuming you have the necessary function declarations and definitions here

int main(void)
{
    // Example data
    int nums[] = {1, 2, 3, 4, 5};

    // Create a list
    t_list *list = NULL;
    for (int i = 0; i < 5; ++i)
        ft_list_push_front(&list, &nums[i]);

    // Display the original list
    printf("Original list:\n");
    t_list *current = list;
    while (current)
    {
        printf("%d ", *(int *)(current->data));
        current = current->next;
    }
    printf("\n");

    // Reverse the list using ft_list_reverse_fun
    ft_list_reverse_fun(list);

    // Display the reversed list
    printf("Reversed list:\n");
    current = list;
    while (current)
    {
        printf("%d ", *(int *)(current->data));
        current = current->next;
    }
    printf("\n");

    // Free the list
    while (list)
    {
        t_list *temp = list;
        list = list->next;
        free(temp);
    }

    return 0;
}*/
