/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:25:00 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/19 00:42:03 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char **tab)
{
	int	size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		count;
	int		size;
	char	*temp;

	count = 0;
	size = ft_len(tab);
	while (count < size - 1)
	{
		if ((*cmp)(tab[count], tab[count + 1]) > 0)
		{
			temp = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = temp;
			count = 0;
		}
		else
			count++;
	}
}
