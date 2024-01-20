/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:33:24 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:38:53 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list->next)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list->next;
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    // Example data
    char *strs[] = {"One", "Two", "Three", "Four", NULL};

    // Create a list
    t_list *list = ft_list_push_strs(4, strs);

    // Display the original list
    printf("Original list:\n");
    t_list *current = list;
    while (current)
    {
        printf("%s ", (char *)(current->data));
        current = current->next;
    }
    printf("\n");

    // Get an element at position 2
    unsigned int position = 2;
    t_list *element = ft_list_at(list, position);

    // Display the element at the specified position
    if (element)
        printf(" %u: %s\n", position, (char *)(element->data));
    else
        printf("%u not found.\n", position);

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
