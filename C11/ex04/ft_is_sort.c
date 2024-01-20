/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:29:19 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/19 01:05:14 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	greater;
	int	smaller;

	i = 0;
	greater = 0;
	smaller = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			greater++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			smaller++;
		i++;
	}
	if (greater == i || smaller == i)
		return (1);
	return (0);
}
