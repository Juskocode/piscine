/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:36:54 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:28:35 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*temp;

	curr = *begin_list;
	prev = NULL;
	while (curr)
	{
		temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	*begin_list = prev;
}
