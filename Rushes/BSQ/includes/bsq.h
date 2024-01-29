/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:26:16 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/29 09:16:55 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BSQ_H
# define BSQ_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 2000001

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		ft_putnbr(int nb);
int		ft_read_maze(int fd, char *buffer, int buffer_size);
int		ft_open_maze(char *filepath);
int		ft_atoi(char *str);
int		ft_strlen(char *str);
char	**allocate_maze(int row, int col);
void		innit_maze(char *buffer, int row, int col, char **maze);
void		print_maze(char **maze, int row, int col);
void    ft_maze_symbols(char *filename, char *obs, char *safe, char *sqr);
int     **ft_bmatrix(char *filename, char **maze, const int row, const int col);
void    ft_print_bmatrix(int **bmatrix, const int row, const int col);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int	**fb_initmem(int col);
void		free_memo(int **memo);
void		ft_max_square(int **bmatrix, int row, int col);

#endif
