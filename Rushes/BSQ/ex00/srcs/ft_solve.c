/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:44:29 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/27 22:17:36 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	**ft_initmem(int col)
{
	int	**mem;
	int	i = 0, j = 0;

	mem = (int **)malloc(sizeof(int **) * 2);
	mem[0] = (int *)malloc(sizeof(int *) * col);
	mem[1] = (int *)malloc(sizeof(int *) * col);

	while (i < 2)
	{
		j = 0;
		while (j < col)
		{
			mem[i][j] = 0;
			j++;
		}
		i++;
	}
	return mem;
}

void	free_memo(int **memo)
{
	int	i;

	i = 0;
	while (i < 2)
		free(memo[i++]);
	free(memo);
}
void	ft_max_square(int **bmatrix, int row, int col)
{
	int	**memo;
	int	i = 0, j = 0, entry, cmax = 0, max_i = 0, max_j = 0;
	
	memo = ft_initmem(col);
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			entry = bmatrix[i][j];
			if (entry)
			{
				entry = 1 + ft_min(memo[1][j - 1],
					       	ft_min(memo[0][j - 1], memo[1][j]));
			}
			
			memo[0][j] = memo[1][j];
			memo[1][j] = entry;
			if (entry > cmax)
			{
				cmax = entry;
				max_i = i;
				max_j = j;
			}
			j++;
		}
		i++;
	}
	ft_putnbr(max_i);
	ft_putstr(", ");
	ft_putnbr(max_j);
	ft_putstr(", ");
	ft_putnbr(cmax);
	ft_putchar('\n');
	for (i = max_i; i > max_i - cmax; i--)
		for (j = max_j; j > max_j - cmax; j--)
			bmatrix[i][j] = 2; 
}
