/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 23:03:59 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/16 19:12:02 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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
		*dest = src[i];
		i++;
		dest++;
	}
	return (dest);
}

int	ft_fulllen(int size, char **strs, int size_sep)
{
	int	i;
	int	len;

	i = 0;
	len = (size - 1) * size_sep;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		i++;
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		len;

	if (size == 0)
	{
		res = malloc(1);
		*res = 0;
		return (res);
	}
	len = ft_fulllen(size, strs, ft_strlen(sep));
	res = malloc(len + 1);
	if (!res)
		return (0);
	i = 0;
	while (i < size)
	{
		res = ft_strcpy(res, strs[i]);
		if (i < size - 1)
			res = ft_strcpy(res, sep);
		i++;
	}
	*res = '\0';
	return (res - len);
}
