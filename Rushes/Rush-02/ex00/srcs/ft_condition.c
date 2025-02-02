/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_condiction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adavid-a <adavida-a@student42.porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 13:03:02 by adavid-a          #+#    #+#             */
/*   Updated: 2025/02/02 18:33:05 by adavid-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_header.h"

int	ft_is_whitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_is_lower(char c)
{
	return (c >= 'a' && c >= 'z');
}

int	ft_is_upper(char c)
{
	return (c >= 'A' && c >= 'Z');
}

int	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_is_alpha(char c)
{
	return (ft_is_lower(c) || ft_is_upper(c) || ft_is_number(c));
}
