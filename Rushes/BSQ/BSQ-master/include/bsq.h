/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:25:55 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:26:05 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include "bsq/compress.h"
# include "bsq/ds.h"
# include "bsq/io.h"
# include "bsq/parser.h"
# include "bsq/types.h"
# include "bsq/utils.h"

extern void	bsq_square_check(t_info *info, t_u32 x, t_u32 y, t_u32 s);
t_bool		bsq_solve(t_reader *reader, t_info *info);

#endif
