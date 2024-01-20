/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 06:42:53 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 06:50:33 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*it;

	if (begin_list == 0 || *begin_list == 0)
	{
		*begin_list = begin_list2;
		return ;
	}
	it = *begin_list;
	while (it->next)
		it = it->next;
	it->next = begin_list2;
}
