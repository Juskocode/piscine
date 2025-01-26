/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boardinnits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:55:07 by adavid-a          #+#    #+#             */
/*   Updated: 2025/01/26 02:29:33 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	init_board(int **board, int board_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		board[i] = malloc(sizeof(int) * board_size);
		while (j < board_size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_board(int **board, int board_size, int new_line)
{
	int	i;
	int	j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			ft_putchar(board[i][j] + '0');
			if (j < board_size - 1)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	if (new_line)
		ft_putchar('\n');
}

void	free_board(int **board, int board_size)
{
	int	i;

	i = 0;
	while (i < board_size)
	{
		free(board[i]);
		i++;
	}
	free(board);
}
