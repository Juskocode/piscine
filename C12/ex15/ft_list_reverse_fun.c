/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 06:59:23 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:33:32 by aaires-d         ###   ########.fr       */
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		n;
	int		i;
	int		j;
	t_list	*it;
	void	*tmp;

	n = 0;
	it = begin_list;
	while (it && ++n)
		it = it->next;
	i = 0;
	while (i < n - 1)
	{
		j = i;
		it = begin_list;
		while (it && it->next && j < n - 1)
		{
			ft_swap(it);
			j++;
		}
		i++;
	}
}
/*
 * #include <stdio.h>
#include <stdlib.h>

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
}
*/
