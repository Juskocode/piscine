/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:03:21 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 20:21:55 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_adjacent_cell(int grid[4][4], int gap, int num)
{
	int	i;

	i = 0;
	while (i < gap / 4)
	{
		if (grid[i][gap % 4] == num)
			return (1);
		i++;
	}
	i = 0;
	while (i < gap % 4)
	{
		if (grid[gap / 4][i] == num)
			return (1);
		i++;
	}
	return (0);
}
