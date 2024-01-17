/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 22:45:25 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/15 22:55:55 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*tab;
	int	size;
	int	i;

	i = 0;
	size = max - min - 1;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(size * 4);
	if (!tab)
		return (-1);
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (size + 1);
}
