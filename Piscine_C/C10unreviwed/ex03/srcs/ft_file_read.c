/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:57:20 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/14 15:38:27 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_file_count(char *filepath)
{
	int			file;
	int			size;
	int			sizetot;
	char		buf[__BUFF];
	extern int	errno;

	file = open(filepath, O_RDONLY);
	if (file != -1)
	{
		sizetot = 0;
		while ((size = read(file, buf, __BUFF)) != 0)
			sizetot += size;
		return (sizetot);
	}
	else
		return (-1);
}

void	ft_file_get(char *filepath, int sizetot, int size)
{
	int		i;
	int		bufsize;
	int		file;
	char	buf[__BUFF];

	file = open(filepath, O_RDONLY);
	i = 0;
	while ((bufsize = read(file, buf, __BUFF)) != 0 &&
			((i + 1) * __BUFF < sizetot - size))
		i++;
	if (size >= sizetot)
		i = -1;
	else
		i = (sizetot - size) - (i * __BUFF) - 1;
	while (++i < __BUFF && i < bufsize)
		ft_putchar(buf[i], 1);
	while ((bufsize = read(file, buf, __BUFF)) != 0)
		ft_putstr_buf(buf, bufsize);
}
