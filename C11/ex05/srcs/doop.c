/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:40:17 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 01:45:48 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	testing(char *n1, char *n2, int ope, int *nb)
{
	nb[0] = ft_atoi(n1);
	nb[1] = ft_atoi(n2);
	if (nb[1] == 0 && (ope == 2 || ope == 4))
	{
		if (ope == 2)
			ft_putstr("Stop : division by zero");
		else
			ft_putstr("Stop : modulo by zero");
		return (0);
	}
	else
		return (1);
}

void	doop(char *n1, char *op, char *n2)
{
	int		(*tab[5])(int, int);
	int		nb[2];

	tab[0] = ft_add;
	tab[1] = ft_sub;
	tab[2] = ft_div;
	tab[3] = ft_mull;
	tab[4] = ft_mod;
	if (getop(op) != -1)
	{
		if (testing(n1, n2, getop(op), nb) != 0)
			ft_putnbr(tab[getop(op)](nb[0], nb[1]));
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(0);
		ft_putchar('\n');
	}
}

int	getop(char *op)
{
	int		i;
	char	*list;

	list = "+-/*%";
	i = -1;
	while (list[++i])
		if (list[i] == op[0] && op[1] == '\0')
			return (i);
	return (-1);
}
