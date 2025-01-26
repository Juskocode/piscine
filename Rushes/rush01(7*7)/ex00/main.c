/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:19:36 by adavid-a          #+#    #+#             */
/*   Updated: 2025/01/26 02:34:23 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

#define PRINT_ONE	0
#define PRINT_ALL	1
#define PRINT_VALID	2

int	full_board_run(int **board, int *user_list, int board_size)
{
	int	valid;

	valid = is_valid_board(board, board_size);
	if (valid)
	{
		if (user_list[-1] == PRINT_ALL)
			print_board(board, board_size, 1);
		if (is_user_solution(board, user_list, board_size))
		{
			if (user_list[-1] != PRINT_ALL)
				print_board(board, board_size, user_list[-1] != PRINT_ONE);
		}
		else
			valid = 0;
	}
	board[board_size - 1][board_size - 1] = 0;
	return (valid);
}

//user_l [board_size, mode(print_one, all, valid)]
int	progress_board(int **board, int x, int y, int *user_l)
{
	int	sol_count;
	int	i;

	i = 0;
	sol_count = 0;
	while (i < user_l[-2])
	{
		board[x][y] = ++i;
		if (!is_valid_board(board, user_l[-2]))
			continue ;
		if (x == user_l[-2] - 1 && y == user_l[-2] - 1)
			return ((full_board_run(board, user_l, user_l[-2])) + sol_count);
		else if (y == user_l[-2] - 1)
			if (user_l[-1] == PRINT_ALL
				|| is_matching_view(board, user_l, x, user_l[-2]))
				sol_count += progress_board(board, x + 1, 0, user_l);
		else
			break ;
		else
			sol_count += progress_board(board, x, y + 1, user_l);
		if (sol_count > 0 && user_l[-1] == PRINT_ONE)
			return (sol_count);
	}
	board[x][y] = 0;
	return (sol_count);
}

int	set_options(int argc, char **argv, int *user_list)
{
	if (argc == 3 && argv[2][0] == 'a')
		user_list[-1] = PRINT_ALL;
	else if (argc == 3 && argv[2][0] == 'v')
		user_list[-1] = PRINT_VALID;
	else if (argc == 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*user_list;
	int	board_size;
	int	**board;

	if (argc < 2 || argc > 3)
	{
		ft_putstr("Error\n");
		return (1);
	}
	board_size = generate_board(argv[1], &user_list);
	if (!user_list || !board_size)
		return (1);
	user_list[-2] = board_size;
	if (set_options(argc, argv, user_list))
		return (1);
	board = malloc(sizeof(int *) * board_size);
	init_board(board, board_size);
	print_nb_sol(progress_board(board, 0, 0, user_list),
		user_list[-1] != PRINT_ONE);
	free_board(board, board_size);
	free(user_list - 2);
	return (0);
}
