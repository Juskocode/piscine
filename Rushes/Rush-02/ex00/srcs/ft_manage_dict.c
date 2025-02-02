/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_dict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <adavid-a@student42.porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 14:32:57 by adavid-a          #+#    #+#             */
/*   Updated: 2025/02/02 18:34:58 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_word_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_number_len(char *str)
{
	int	i;

	i = 0;
	while (ft_is_number(str[i]))
		i++;
	return (i);
}

char	*ft_get_dict_word(char *str)
{
	int		i;
	int		j;
	int		word_len;
	char	*dest;

	i = 0;
	while (str[i] != ':')
		i++;
	if (str[i] == ':')
		i++;
	while (str[i] == ' ')
		i++;
	word_len = ft_word_len(str + i);
	dest = malloc(sizeof(char) * (word_len + 1));
	if (!dest)
		return (0);
	*dest = 0;
	j = 0;
	while (str[i])
		dest[j++] = str[i++];
	dest[word_len] = '\0';
	return (dest);
}

char	*ft_get_dict_number(char *line)
{
	int		i;
	int		nbr_len;
	char	*nbr;

	i = 0;
	nbr_len = ft_number_len(line);
	nbr = malloc(sizeof(char) * (nbr_len + 1));
	if (!nbr)
		return (0);
	*nbr = 0;
	while (ft_is_alpha(line[i]))
	{
		nbr[i] = line[i];
		i++;
	}
	nbr[nbr_len] = '\0';
	return (nbr);
}
