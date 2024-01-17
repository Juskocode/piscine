/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:04:37 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/15 14:07:58 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_safe_search(int tab[10], int x, int y)
{
	int	i;

	i = -1;
	while (++i < x)
		if (y == tab[i]
			|| i + tab[i] == x + y
			|| i - tab[i] == x - y)
			return (0);
	return (1);
}

void	backtrack(int tab[10], int *res, int pos)
{
	int	i;
	int	j;

	if (pos == 10)
	{
		*res += 1;
		j = -1;
		while (++j < 10)
			ft_putchar(tab[j] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (is_safe_search(tab, pos, i))
			{
				tab[pos] = i;
				backtrack(tab, res, pos + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int	i;
	int	res;

	i = -1;
	while (++i < 10)
		tab[i] = -1;
	res = 0;
	backtrack(tab, &res, 0);
	return (res);
}
