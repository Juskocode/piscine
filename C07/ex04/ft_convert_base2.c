/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:32:23 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/16 21:14:51 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_power(int n, int p)
{
	int	result;

	result = 1;
	if (p < 0)
		return (0);
	while (p > 0)
	{
		result *= n;
		p--;
	}
	return (result);
}

int	get_len(long int nbr, int size, int is_neg)
{
	int	i;

	i = 0;
	if (is_neg == -1)
		i++;
	while (nbr > 0)
	{
		nbr /= size;
		i++;
	}
	return (i);
}

char	*ft_print_rc(long int nbr, char *base, char *res, int is_neg)
{
	int		i;
	int		size;

	i = 0;
	size = get_len(nbr, ft_strlen(base), is_neg);
	if (is_neg == -1)
		res[0] = '-';
	if (nbr == 0)
	{
		res[0] = base[0];
		res[1] = '\0';
	}
	while (nbr > 0)
	{
		res[(size - i - 1)] = base[nbr % ft_strlen(base)];
		i++;
		nbr /= ft_strlen(base);
	}
	return (res);
}

char	*ft_putnbr_base(long int nbr, char *base, int is_neg)
{
	long int	nb;
	char		*res;
	int			size;
	int			len;

	nb = nbr;
	size = ft_strlen(base);
	len = get_len(nb, size, is_neg);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	if ((is_neg == -1 && len == 1) || (len == 0 && is_neg == 0))
	{
		res[0] = base[0];
		return (res);
	}
	return (ft_print_rc(nb, base, res, is_neg));
}
