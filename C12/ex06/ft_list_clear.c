/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:16:24 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:27:48 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*it;

	if (!begin_list)
		return ;
	it = begin_list;
	while (it)
	{
		(*free_fct)(begin_list->data);
		it = begin_list->next;
		free(begin_list);
		begin_list = it;
	}
}
/*
#include <stdio.h>

void free_function(void *data)
{
    // Example free function; replace with your own implementation
    free(data);
}

int main(void)
{
    // Example data
    char *strs[] = {"Hello", "World", "!", NULL};

    // Create a list
    t_list *list = ft_list_push_strs(3, strs);

    // Display the original list
    printf("Original list:\n");
    t_list *current = list;
    while (current)
    {
        printf("%s ", (char *)(current->data));
        current = current->next;
    }
    printf("\n");

    // Clear the list using ft_list_clear
    ft_list_clear(list, &free_function);

    // Display the cleared list (should be empty)
    printf("Cleared list:\n");
    current = list;
    while (current)
    {
        printf("%s ", (char *)(current->data));
        current = current->next;
    }
    printf("\n");

    return 0;
}
*/
