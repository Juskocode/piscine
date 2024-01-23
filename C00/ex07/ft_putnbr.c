/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:40:34 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/10 22:36:40 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	printmaxint(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	printmaxint(void)
{
	write(1, "-2147483648", 11);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		printmaxint();
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			ft_putchar('-');
		}
		if (nb < 10)
		{
			ft_putchar(nb + '0');
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}
