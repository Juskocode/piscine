/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:00:40 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 20:16:55 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_down(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (gap / 4 == 3)
	{
		while (i >= 0)
		{
			if (grid[i][gap % 4] > max)
			{
				max = grid[i][gap % 4];
				count++;
			}
			i--;
		}
		if (pattern[4 + gap % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_left(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (gap % 4 == 3)
	{
		while (i < 4)
		{
			if (grid[gap / 4][i] > max)
			{
				max = grid[gap / 4][i];
				count++;
			}
			i++;
		}
		if (pattern[8 + gap / 4] != count)
			return (1);
	}
	return (0);
}
