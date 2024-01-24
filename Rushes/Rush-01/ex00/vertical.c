/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:00:05 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 20:22:46 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (gap / 4 == 3)
	{
		while (i < 4)
		{
			if (grid[i][gap % 4] > max)
			{
				max = grid[i][gap % 4];
				count++;
			}
			i++;
		}
		if (pattern[gap % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_right(int grid[4][4], int gap, int pattern[16])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	if (gap % 4 == 3)
	{
		while (--i >= 0)
		{
			if (grid[gap / 4][i] > max_size)
			{
				max_size = grid[gap / 4][i];
				visible_towers++;
			}
		}
		if (pattern[12 + gap / 4] != visible_towers)
			return (1);
	}
	return (0);
}
