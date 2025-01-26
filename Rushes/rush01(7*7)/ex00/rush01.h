/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:12:23 by adavid-a          #+#    #+#             */
/*   Updated: 2025/01/26 02:56:25 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <stdlib.h>
# include <unistd.h>

// board_aff.c
void	init_board(int **board, int board_size);
void	print_board(int **board, int board_size, int new_line);
void	free_board(int **board, int board_size);

// count_visible.c
int		count_visible(int **board, int view, int pos, int board_size);

// utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		count_words(char *str);
int		ft_atoi_lite(char *str);

// parser.c
int		generate_board(char *str, int **user_board);
void	print_nb_sol(int nb, int does_print);

// isvalid.c
int		is_valid_board(int **board, int board_size);
int		is_user_solution(int **board, int *user_list, int board_size);
int		is_matching_view(int **board, int *user_list, int y, int board_size);

// ft_putnbr.c
void	ft_putnbr(int nb);

#endif
