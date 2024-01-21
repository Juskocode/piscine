/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:54:30 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/20 07:54:37 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# define __BUFF 30000

# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

void    ft_putchar(char c, int out);
void    ft_swap(int *a, int *b);
void    ft_putstr(char *str, int out);
void    ft_putstr_buf(char *str, int size);
int             ft_strlen(char *str);
int             ft_strcmp(char *s1, char *s2);
int             ft_file_read(char *filepath);

void    no_args(char **argv);

#endif
