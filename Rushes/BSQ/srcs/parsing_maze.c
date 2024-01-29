/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_maze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:38:43 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/29 10:20:01 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_open_maze(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error opening file\n");
		exit(1);
	}
	return (fd);
}

int	ft_read_maze(int fd, char *buffer, int buffer_size)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, buffer_size);
	if (bytes_read == -1)
	{
		ft_putstr("Error reading file\n");
		exit(1);
	}
	return (bytes_read);
}

char	**allocate_maze(int row, int col)
{
	int 	i = 0;
	char	**maze;
	if (!row && !col)
		return (0);
	
	maze = (char **)malloc(row * sizeof(char*));
	while (i < row)
	{
		maze[i] = (char *)malloc(col * sizeof(char));
		i++;
	}
	if (maze == NULL)
	{
		ft_putstr("Memory allocation failed\n");
		exit(1);
	}
	return (maze);
}

void	innit_maze(char *buffer, int num_lines, int num_columns,
		char **maze)
{
	char *ptr;
	int i = 0, j = 0;
	
	while (*buffer != '\n')
		buffer++;
	ptr = buffer + 1;
	while (i < num_lines)
	{
		j = 0;
		while (j < num_columns)
		{
			maze[i][j] = *ptr;
			ptr++;
			j++;
		}
		i++;
		ptr++;
	}
}

void	print_maze(char **maze, int num_lines, int num_columns)
{
	int i = 0, j = 0;
	
	while (i < num_lines)
	{
		j = 0;
		while (j < num_columns)
		{
			ft_putchar(maze[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
