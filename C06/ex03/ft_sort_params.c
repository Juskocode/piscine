/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 10:59:02 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/14 12:31:26 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 == *s2) && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	print_params(char **params)
{
	while (*params)
	{
		ft_putstr(*params++);
		write(1, "\n", 1);
	}
}

void	sort(int size, char *params[])
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(params[j], params[j + 1]) > 0)
			{
				temp = params[j];
				params[j] = params[j + 1];
				params[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		sort(argc - 1, argv + 1);
		print_params(argv + 1);
	}
	return (0);
}
