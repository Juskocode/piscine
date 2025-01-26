/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countvisible.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:15:47 by adavid-a          #+#    #+#             */
/*   Updated: 2025/01/26 02:53:00 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// index is [row, col]
int	get_index(int board_size, int i, int view, int *index)
{
	if (view == 0)
	{
		index[0] = i;
		index[1] = 0;
	}
	else if (view == 1)
	{
		index[0] = board_size - 1 - i;
		index[1] = 0;
	}
	else if (view == 2)
	{
		index[0] = 0;
		index[1] = i;
	}
	else if (view == 3)
	{
		index[0] = 0;
		index[1] = board_size - 1 - i;
	}
	else
		return (0);
	return (1);
}

// check all views
int	count_visible(int **board, int view, int pos, int board_size)
{
	int	count;
	int	max;
	int	i;
	int	index[2];

	count = 0;
	max = 0;
	i = 0;
	while (i < board_size)
	{
		if (!get_index(board_size, i, view, index))
			return (0);
		if (view < 2)
			index[1] = pos;
		else
			index[0] = pos;
		if (board[index[0]][index[1]] > max)
		{
			max = board[index[0]][index[1]];
			count++;
		}
		i++;
	}
	return (count);
}
