/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:27:35 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:27:38 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "utils.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE (4096)
# define TRUE (1)
# define FALSE (0)

typedef unsigned int	t_u32;
typedef unsigned short	t_u16;
typedef unsigned char	t_u8;
typedef t_u8			t_bool;

typedef struct s_bsq_info
{
	t_u8				empty;
	t_u8				obst;
	t_u8				square;
	t_u32				height;
	t_u32				width;
	t_u32				x;
	t_u32				y;
	t_u32				m;
	t_u32				i0;
	t_u32				i1;
	t_u8				i2;
}						t_info;

#endif
