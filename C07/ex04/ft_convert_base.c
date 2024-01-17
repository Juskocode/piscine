/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:14:48 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/16 21:11:04 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_power(int n, int p);
char	*ft_putnbr_base(int nbr, char *base, int is_neg);

int	check_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[j] == '+' || base[j] == '-'
				|| base[j] == ' ' || (base[j] >= 9 && base[j] <= 13))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	*check_sign(char *str, int *is_neg)
{
	*is_neg = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*is_neg *= -1;
		str++;
	}
	return (str);
}

char	*ft_atoi(char *str, char *base, int *is_neg, int *size)
{
	int	i;
	int	j;
	int	valid;

	i = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	str = check_sign(str, is_neg);
	while (*str != '\0')
	{
		j = -1;
		valid = 0;
		while (base[++j] != '\0')
			if (*str == base[j])
				valid = 1;
		if (valid == 0)
			break ;
		str++;
		i++;
	}
	*size = i;
	return (str - i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	nb;
	int			is_neg;
	int			size;
	int			ps;
	int			n;

	nb = 0;
	ps = 0;
	nbr = ft_atoi(nbr, base_from, &is_neg, &size);
	if (check_valid(base_from) == 0 || check_valid(base_to) == 0)
		return (NULL);
	while (ps < size)
	{
		n = 0;
		while (base_from[n] != nbr[ps])
			n++;
		nb += n * ft_power(ft_strlen(base_from), (size - ps - 1));
		ps++;
	}
	return (ft_putnbr_base(nb, base_to, is_neg));
}
