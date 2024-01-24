/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 23:00:45 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/14 17:34:58 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	atoi_recursive(const char *str, int result)
{
	if (!*str)
		return (result);
	if (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		return (atoi_recursive(str + 1, result));
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == ' ' || (*str >= 9 && *str <= 13))
		return (ft_atoi(str + 1));
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (sign * atoi_recursive(str, 0));
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 3)
	{
		write(2, "Function requests 2 arguments!", 31);
		return (1);
	}
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if ((x == 0 && argv[1][0] != '0') || x <= 0)
	{
		write(2, "Error for value x", 17);
		return (1);
	}
	if ((y == 0 && argv[2][0] != '0') || y <= 0)
	{
		write(2, "Error for value y", 17);
		return (1);
	}
	rush(x, y);
	return (0);
}
