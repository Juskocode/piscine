/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:13:43 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 04:19:01 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*it;

	it = begin_list;
	while (it->next)
	{
		if (!(*cmp)(it->data, data_ref))
			return (it);
		it = it->next;
	}
	return (0);
}
