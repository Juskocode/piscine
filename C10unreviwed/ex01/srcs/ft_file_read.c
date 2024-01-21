/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybayart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 14:57:20 by ybayart           #+#    #+#             */
/*   Updated: 2019/08/15 03:38:35 by ybayart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_file_read(char *filepath)
{
	int			file;
	int			size;
	char		buf[__BUFF];

	file = open(filepath, O_RDWR);
	if (file != -1)
	{
		while ((size = read(file, buf, __BUFF)) != 0)
			ft_putstr_buf(buf, size);
		return (1);
	}
	else
		return (0);
}
