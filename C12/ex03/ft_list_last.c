/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:03:04 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:22:01 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_last)
{
	while (begin_last->next)
		begin_last = begin_last->next;
	return (begin_last);
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

    return 0;
}
*/
