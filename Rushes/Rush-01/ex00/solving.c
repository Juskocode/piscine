/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:31:15 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 20:21:14 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int gap, int pattern[16]);

int	check_row_right(int grid[4][4], int gap, int patern[16]);

int	check_col_down(int grid[4][4], int gap, int pattern[16]);

int	check_row_left(int grid[4][4], int gap, int pattern[16]);

int	check_cell(int grid[4][4], int gap, int pattern[16])
{
	if (check_row_left(grid, gap, pattern) == 1)
		return (1);
	if (check_row_right(grid, gap, pattern) == 1)
		return (1);
	if (check_col_down(grid, gap, pattern) == 1)
		return (1);
	if (check_col_up(grid, gap, pattern) == 1)
		return (1);
	return (0);
}
