/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:45:48 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/18 22:53:22 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>

void	doop(char *n1, char *op, char *n2);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mull(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
int		ft_atoi(char *str);
int		getop(char *op);

#endif
