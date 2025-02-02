/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <adavid-a@student42.porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:08:49 by adavid-a          #+#    #+#             */
/*   Updated: 2025/02/02 18:58:52 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

void	ft_error(void)
{
	write (2, "Error\n", 6);
}

void	ft_error_dict(void)
{
	write (2, "Dict Error\n", 11);
}

int	main(int argc, char **argv)
{
	char	*dictpath;
	char	*nbr;

	if (!ft_check_args(argc, argv, &dictpath, &nbr))
	{
		ft_error();
		return (1);
	}
	if (!ft_check_dict(dictpath))
	{
		free(nbr);
		ft_error_dict();
		return (1);
	}
	if (!ft_init(dictpath, nbr))
	{
		ft_error_dict();
		return (1);
	}
	return (0);
}
