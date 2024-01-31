/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 19:27:08 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/31 19:27:10 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_H
# define IO_H

# include "types.h"

typedef struct s_reader
{
	t_u8		buf[BUF_SIZE + 1];
	t_u16		cursor;
	t_u16		len;
	t_u8		fd;
}				t_reader;

extern t_reader	*bsq_reader(t_reader *reader, t_u8 fd);
extern t_u8		bsq_next(t_reader *reader);

typedef struct s_writer
{
	t_u8		buf[BUF_SIZE];
	t_u16		cursor;
}				t_writer;

extern t_writer	bsq_writer(void);
extern void		bsq_write(t_writer *writer, t_u8 c);
extern void		bsq_idea(t_writer *writer);

#endif
