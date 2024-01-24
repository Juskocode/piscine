/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 23:16:26 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/19 00:23:04 by aaires-d         ###   ########.fr       */
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

void	ft_sort_string_tab(char **tab)
{
	int		count;
	int		size;
	char	*tmp;

	count = 0;
	size = ft_len(tab);
	while (count < size - 1)
	{
		if (ft_strcmp(tab[count], tab[count + 1]) > 0)
		{
			tmp = tab[count];
			tab[count] = tab[count + 1];
			tab[count + 1] = tmp;
			count = 0;
		}
		else
			count++;
	}
}
