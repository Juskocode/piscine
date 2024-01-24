/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 17:26:03 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/18 23:07:10 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int lenght, int (*f)(int))
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(lenght * 4);
	if (!res)
		return (0);
	while (i < lenght)
	{
		res[i] = (*f)(tab[i]);
		i++;
	}
	return (res);
}
