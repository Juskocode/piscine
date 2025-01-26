/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:05:23 by adavid-a          #+#    #+#             */
/*   Updated: 2025/01/26 02:30:47 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_valid_case(int **board, int i, int j, int board_size)
{
	int	k;

	k = 0;
	while (k < board_size)
	{
		if (!board[i][j])
			continue ;
		if (k != i && board[k][j] == board[i][j])
			return (0);
		if (k != j && board[i][k] == board[i][j])
			return (0);
		k++;
	}
	return (1);
}

// do not care about zero
int	is_valid_board(int **board, int board_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < board_size)
	{
		j = 0;
		while (j < board_size)
		{
			if (board[i][j] != 0 && !is_valid_case(board, i, j, board_size))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_user_solution(int **board, int *user_list, int board_size)
{
	int	i;

	i = 0;
	while (user_list[i])
	{
		if (count_visible(board, i / board_size, i % board_size, board_size)
			!= user_list[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_matching_view(int **board, int *user_list, int y, int board_size)
{
	if (count_visible(board, 2, y, board_size) != user_list[board_size * 2 + y])
		return (0);
	if (count_visible(board, 3, y, board_size) != user_list[board_size * 3 + y])
		return (0);
	return (1);
}
