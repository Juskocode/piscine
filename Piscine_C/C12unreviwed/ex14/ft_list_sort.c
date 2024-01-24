/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 06:51:44 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:31:54 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(t_list *it)
{
	void	*data;

	data = it->data;
	it->data = it->next->data;
	it->next->data = data;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*it1;
	t_list	*it2;

	it1 = *begin_list;
	while (it1)
	{
		it2 = *begin_list;
		while (it2)
		{
			if ((*cmp)(it2->data, it2->next->data) > 0)
				ft_swap(it2);
			it2 = it2->next;
		}
		it1 = it1->next;
	}
}
/*
#include <stdio.h>
// Example comparison function for sorting integers in ascending order
int compare_integers(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    // Example data
    int nums[] = {5, 2, 8, 1, 3};

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

    // Sort the list using ft_list_sort
    ft_list_sort(&list, &compare_integers);

    // Display the sorted list
    printf("Sorted list:\n");
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
}
*/
