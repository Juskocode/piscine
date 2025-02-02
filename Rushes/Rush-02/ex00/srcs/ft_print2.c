/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <adavid-a@student42.porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:55:21 by adavid-a          #+#    #+#             */
/*   Updated: 2025/02/02 18:35:22 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_print_figure(char *nbr, char **dict)
{
	int		i;
	char	*dict_word;
	char	*dict_number;

	i = 0;
	while (dict[i])
	{
		dict_word = ft_get_dict_word(dict[i]);
		dict_number = ft_get_dict_number(dict[i]);
		if (ft_strcmp(nbr, dict_number) == 0)
		{
			ft_putstr(dict_word);
			free(dict_word);
			free(dict_number);
			return (1);
		}
		free(dict_word);
		free(dict_number);
		i++;
	}
	return (0);
}

int	ft_print_exact_value(char *nbr, char **dict)
{
	int		i;
	char	*dict_word;
	char	*dict_number;

	i = 0;
	while (dict[i])
	{
		dict_word = ft_get_dict_word(dict[i]);
		dict_number = ft_get_dict_number(dict[i]);
		if (ft_strcmp(nbr, dict_number) == 0)
		{
			ft_putstr(dict_word);
			free(dict_word);
			free(dict_number);
			return (1);
		}
		free(dict_word);
		free(dict_number);
		i++;
	}
	return (0);
}
