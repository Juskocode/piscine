/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <adavid-a@student42.porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:06:31 by adavid-a          #+#    #+#             */
/*   Updated: 2025/02/02 18:34:33 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_free(char **dict, char **tab_nbr, char *nbr, char *zerovalue)
{
	int	i;

	i = 0;
	while (dict[i])
	{
		free(dict[i]);
		i++;
	}
	free(dict);
	i = 0;
	while (tab_nbr[i])
	{
		free(tab_nbr[i]);
		i++;
	}
	free(tab_nbr);
	free(nbr);
	free(zerovalue);
}
