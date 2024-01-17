/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 06:41:20 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/17 06:42:13 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

int					main(void)
{
	char	*strs[4];
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;
	int		size;

	str1 = "Eu";
	str2 = "42";
	str3 = "nadar";
	str4 = "ez C08";
	size = 4;
	strs[0] = str1;
	strs[1] = str2;
	strs[2] = str3;
	strs[3] = str4;
	ft_strs_to_tab(size, strs);
}
