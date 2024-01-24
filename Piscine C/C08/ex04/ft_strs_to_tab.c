/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 06:27:13 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/17 06:40:15 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *str)
{
	char	*dup;

	dup = malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	dup = ft_strcpy(dup, str);
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*strs;

	strs = malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!strs)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		strs[i].str = av[i];
		strs[i].size = ft_strlen(av[i]);
		strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs[i].size = 0;
	strs[i].str = 0;
	strs[i].copy = 0;
	return (strs);
}
