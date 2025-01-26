/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 02:09:18 by adavid-a          #+#    #+#             */
/*   Updated: 2025/01/26 02:29:13 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	fill_list(int *user_list, int max_val, int wc, char *str)
{
	int	lst_i;
	int	i;

	i = 0;
	lst_i = 0;
	while (lst_i < wc)
	{
		while (str[i] == ' ')
			i++;
		user_list[lst_i] = ft_atoi_lite(str + i);
		if (user_list[lst_i] > max_val || user_list[lst_i] < 1)
		{
			ft_putstr("Error\n");
			return (0);
		}
		i++;
		lst_i++;
	}
	user_list[lst_i] = 0;
	return (max_val);
}

int	generate_board(char *str, int **user_board)
{
	int	max_val;
	int	wc;

	*user_board = 0;
	wc = count_words(str);
	if (wc % 4)
	{
		ft_putstr("Error\n");
		return (0);
	}
	max_val = wc / 4;
	if (max_val > 9 || max_val < 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	*user_board = malloc(sizeof(int) * (wc + 3));
	if (!(*user_board))
		return (0);
	(*user_board)[0] = 0;
	(*user_board)[1] = 0;
	(*user_board) += 2;
	return (fill_list(*user_board, max_val, wc, str));
}

void	print_nb_sol(int nb, int does_print)
{
	if (!does_print)
	{
		if (!nb)
			ft_putstr("Error\n");
		return ;
	}
	ft_putstr("found ");
	ft_putnbr(nb);
	ft_putstr(" solution");
	if (nb > 1)
		ft_putchar('s');
	ft_putchar('\n');
}
