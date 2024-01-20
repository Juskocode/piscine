/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 04:02:15 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 04:07:54 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *), void
*data_ref, int (*cmp)())
{
	t_list	*it;

	it = begin_list;
	while (it->next)
	{
		if (!(*cmp)(it->data, data_ref))
			(*f)(it->data);
		it = it->next;
	}
}
