/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:18 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/13 23:22:36 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_tolower(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += 32;
		i++;
	}
}

int	ft_is_alpha(char c)
{
	if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

int	ft_is_digit(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

int	ft_is_lower(char c)
{
	if (!(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	capnext;
	int	i;

	i = 0;
	ft_tolower(str);
	capnext = 1;
	while (str[i])
	{
		if (ft_is_alpha(str[i]) || ft_is_digit(str[i]))
		{
			if (ft_is_lower(str[i]) && capnext)
				str[i] -= 32;
			capnext = 0;
		}
		else
			capnext = 1;
		i++;
	}
	return (str);
}
