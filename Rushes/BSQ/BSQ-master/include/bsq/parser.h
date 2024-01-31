/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:27:18 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:27:24 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "compress.h"
# include "ds.h"
# include "io.h"
# include "types.h"

extern t_info	*bsq_validate_info(t_info *info);
extern t_info	*bsq_info_ctor(t_info *info, t_reader *reader);
extern int		bsq_read_first(t_reader *reader, t_info *info, t_lbuf **first,
					t_matrix *matrix);

#endif
