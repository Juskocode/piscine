/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:39:03 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/16 19:06:09 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	range = malloc(((max - min) * 4) - 1);
	while (min < max)
	{
		range[i] = min;
		i++;
		min++;
	}
	return (range);
}
/*
#include <stdio.h>

int	main()
{
	int		*range;
	int	i;
	int	min;
	int	max;

	min = 4;
	max = 1;
	i = 0;
	range = ft_range(min, max);
	while (i++ < max - min - 1)
	{
		if (i < max - min - 2)
			printf("%d, ", range[i]);
		else
			printf("%d", range[i]);
	}

	return (0);
}*/
