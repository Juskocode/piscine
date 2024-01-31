/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:28:41 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:28:43 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#define SNS(s) (s), (sizeof(s) - 1)

int	main(int ac, char **av)
{
	t_reader	reader;
	t_info		info;
	t_u8		i;

	i = 0;
	if (ac > 1)
		while (++i < ac)
		{
			if (bsq_reader(&reader, (t_u8)open(av[i], O_RDONLY)) == NULL
				|| bsq_info_ctor(&info, &reader) == NULL || bsq_solve(&reader,
					&info) == FALSE)
				write(2, SNS(PARSE_ERR));
			else
				BSQ_ASSERT(close(reader.fd) != -1, IO_FAIL);
			if (i < ac - 1)
				write(1, SNS("\n"));
		}
	else if (bsq_reader(&reader, 0) == NULL || bsq_info_ctor(&info,
			&reader) == NULL || bsq_solve(&reader, &info) == FALSE)
		write(2, SNS(PARSE_ERR));
	return (EXIT_SUCCESS);
}
