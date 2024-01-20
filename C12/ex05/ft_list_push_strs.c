/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:39:58 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:25:43 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*itprev;
	t_list	*it;

	if (size <= 0)
		return (0);
	itprev = ft_create_elem(strs[0]);
	i = 1;
	while (strs[i])
	{
		it = ft_create_elem(strs[i]);
		it->next = itprev;
		itprev = it;
		i++;
	}
	return (itprev);
}

/*
#include <stdio.h>

int main(void)
{
    char *strs[] = {"Hello", "World", "!", NULL};

    t_list *list = ft_list_push_strs(3, strs);

    t_list *current = list;
    while (current)
    {
        printf("%s ", (char *)(current->data));
        current = current->next;
    }
    printf("\n");

    return 0;
}
*/
