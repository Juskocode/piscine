/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:30:27 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 20:14:28 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

int		ft_atoi(char *str);

void	ft_putnbr(int nb);

int		check_arguments(int argc, char *argv[]);

int		*convert_pattern(char *str);

void	print_puzzle_grid(int grid[4][4]);

int		check_cell(int grid[4][4], int gap, int pattern[16]);

int		check_col_up(int grid[4][4], int gap, int pattern[16]);

int		check_row_right(int grid[4][4], int gap, int patern[16]);

int		check_col_down(int grid[4][4], int gap, int pattern[16]);

int		check_row_left(int grid[4][4], int gap, int pattern[16]);

int		check_adjacent_cell(int grid[4][4], int gap, int num);

int	puzzle_solver(int grid[4][4], int pattern[16], int gap)
{
	int	num;

	if (gap == 16)
		return (1);
	num = 0;
	while (++num <= 4)
	{
		if (check_adjacent_cell(grid, gap, num) == 0)
		{
			grid[gap / 4][gap % 4] = num;
			if (check_cell(grid, gap, pattern) == 0)
			{
				if (puzzle_solver(grid, pattern, gap + 1) == 1)
					return (1);
			}
			else
				grid[gap / 4][gap % 4] = 0;
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	*pattern;
	int	grid[4][4];
	int	i;
	int	j;

	i = 0;
	while (i++ < 4)
	{
		j = 0;
		while (j < 4)
			grid[i][j++] = 0;
	}
	if (check_arguments(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	pattern = convert_pattern(argv[1]);
	if (!pattern)
		return (1);
	if (puzzle_solver(grid, pattern, 0) == 1)
		print_puzzle_grid(grid);
	else
		ft_putstr("Error\n");
	return (0);
}
