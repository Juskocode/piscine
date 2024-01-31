/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:26:23 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:26:28 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPRESS_H
# define COMPRESS_H

# include "ds.h"
# include "io.h"
# include "types.h"

typedef struct s_matrix
{
	t_lbuf		*lbuf;
	t_lbuf		*root;
	t_u32		cursor;
}				t_matrix;

# define BINARY_MATRIX 0
# define REPEAT_MATRIX 1

extern t_matrix	matrix(void);
extern t_bool	matrix_write(t_matrix *matrix, t_bool value);
void			matrix_print(t_matrix *matrix, t_info *info);
extern void		bsq_print_at(t_bool val, t_info *info, t_u32 e,
					t_writer *writer);

#endif
