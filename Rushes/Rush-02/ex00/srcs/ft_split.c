/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <adavid-a@student42.porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:02:45 by adavid-a          #+#    #+#             */
/*   Updated: 2025/02/02 18:36:22 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

char	*ft_add_word(char *src, int size)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc (sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_charset(str[i], charset))
		i++;
	return (i);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	count;
	int	word_len;

	i = 0;
	count = 0;
	word_len = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		word_len = ft_count_word_len(str + i, charset);
		if (word_len)
			count++;
		i += word_len;
		word_len = 0;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		word_len;
	int		count_word;
	char	**tab;

	i = 0;
	j = 0;
	word_len = 0;
	count_word = ft_count_word(str, charset);
	tab = malloc(sizeof(char *) * (count_word + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			i++;
		word_len = ft_count_word_len(str + i, charset);
		if (word_len)
			tab[j++] = ft_add_word(str + i, word_len);
		i += word_len;
		word_len = 0;
	}
	tab[j] = 0;
	return (tab);
}
