/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 22:30:19 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/14 09:38:51 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_logic_line(int x, char inside, char left, char right)
{
	ft_putchar(left);
	while (--x > 1)
		ft_putchar(inside);
	if (x > 0)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	print_logic_line(x, 'B', 'A', 'C');
	while (--y > 1)
		print_logic_line(x, ' ', 'B', 'B');
	if (y > 0)
		print_logic_line(x, 'B', 'C', 'A');
}
