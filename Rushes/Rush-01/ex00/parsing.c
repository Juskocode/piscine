/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:30:49 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/21 20:19:44 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar(char c);

void	ft_putstr(char *str);

int		ft_strlen(char *str);

int		ft_atoi(char *str);

void	ft_putnbr(int nb);

int	check_arguments(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (argc != 2)
		return (1);
	str = argv[0];
	if (ft_strlen(argv[1]) != 31)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			j = ft_atoi(str + i);
			if (j < 0 || j > 4)
				return (0);
		}
		i++;
	}
	return (0);
}

int	*convert_pattern(char *str)
{
	int	*tab;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(int) * 16);
	if (!tab)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			tab[j++] = ft_atoi(str + i);
		i++;
	}
	return (tab);
}

void	print_puzzle_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(grid[i][j]);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
