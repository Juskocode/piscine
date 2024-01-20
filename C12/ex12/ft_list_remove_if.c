/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:20:14 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 06:40:43 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*it;
	t_list	*temp;

	it = *begin_list;
	while (it && it->next)
	{
		if (!(*cmp)(it->next->data, data_ref))
		{
			temp = it->next;
			it->next = it->next->next;
			(*free_fct)(temp->data);
			free(temp);
		}
		it = it->next;
	}
	it = *begin_list;
	if (it && !(*cmp)(it->data, data_ref))
	{
		*begin_list = it->next;
		(*free_fct)(it->data);
		free(it);
	}
}
/*
#include <stdio.h>

// Assuming the structure and functions are defined here...

// Example comparison function (you may need to implement your own)
int compare_int(void *a, void *b) {
    return (*(int*)a - *(int*)b);
}

// Example function to free memory for integer data
void free_int(void *data) {
    free(data);
}

int main() {
    // Creating a sample linked list of integers
    t_list *list = NULL;
    int *data1 = malloc(sizeof(int));
    int *data2 = malloc(sizeof(int));
    int *data3 = malloc(sizeof(int));

    *data1 = 10;
    *data2 = 20;
    *data3 = 10;

    list = ft_create_elem(data1);
    list->next = ft_create_elem(data2);
    list->next->next = ft_create_elem(data3);

    // Printing the original list
    printf("Original List: ");
    t_list *current = list;
    while (current) {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");

    // Removing elements with the value 10
    int value_to_remove = 10;
    ft_list_remove_if(&list, &value_to_remove, compare_int, free_int);

    // Printing the modified list
    printf("Modified List: ");
    current = list;
    while (current) {
        printf("%d ", *(int*)current->data);
        current = current->next;
    }
    printf("\n");

    // Freeing the remaining memory
    current = list;
    while (current) {
        t_list *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }

    return 0;
}
*/
