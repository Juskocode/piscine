/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 01:57:56 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:20:53 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
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

    printf("Size of the list: %d\n", ft_list_size(list));

    free(list);

    return 0;
}
*/
