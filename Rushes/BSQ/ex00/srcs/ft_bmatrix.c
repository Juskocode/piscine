/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:32:51 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/27 19:49:24 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_maze_symbols(char *filename, char *obs, char *safe, char *sqr)
{
	int	fd;
	int	i;
	char	buffer[BUFFER_SIZE];
	
	fd = ft_open_maze(filename);
	ft_read_maze(fd, buffer, BUFFER_SIZE);
	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	*safe = buffer[i++];
	*obs = buffer[i++];
	*sqr = buffer[i];
}

int	**ft_bmatrix(char *filename, char **maze, const int row, const int col)
{
	char	obs, safe, sqr;
	int	i = 0, j;
	int	**bmaze;
	ft_maze_symbols(filename, &obs, &safe, &sqr);
	
	bmaze = (int **)malloc(row * sizeof(int *));
	while (i < row)
		bmaze[i++] = (int *)malloc(col * sizeof(int));
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			if (maze[i][j] == safe)
				bmaze[i][j] = 1;
			else
				bmaze[i][j] = 0;
			j++;
		}
		i++;
	}
	return bmaze;
}

void	ft_print_bmatrix(int **bmatrix, const int row, const int col)
{
	int	i = 0, j = 0;

	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			ft_putchar(bmatrix[i][j] + '0');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}






















