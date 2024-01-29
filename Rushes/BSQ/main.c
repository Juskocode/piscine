/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:16:06 by aaires-d          #+#    #+#             */
/*   Updated: 2024/01/29 10:48:11 by aaires-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        ft_putstr("Usage: ./bsq <maze_file>\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int fd = ft_open_maze(argv[1]);
    ft_read_maze(fd, buffer, BUFFER_SIZE);

    int num_lines = ft_atoi(buffer);
    int i = 0;
    while ('0' <= buffer[i] && buffer[i] <= '9')
	    i++;
    int k = 0;
    int num_columns = 0;
    char f[3];

    while (buffer[i] != '\n') {
	f[k] = buffer[i];
        i++;
	k++;
    }
    i++;
    while (buffer[i] != '\n' && buffer[i])
    {
    	i++;
	num_columns++;
    }

    char **maze = allocate_maze(num_lines,  num_columns);

    innit_maze(buffer, num_lines, num_columns, maze);

    close(fd);

    print_maze(maze, num_lines, num_columns);
    int **bmaze = ft_bmatrix(argv[1], maze, num_lines, num_columns);
    ft_putnbr(num_lines);
    ft_putstr(", ");
    ft_putnbr(num_columns);
    ft_putchar('\n');
    ft_max_square(bmaze, num_lines, num_columns);
    for (i = 0; i < num_lines; i++)
    {
    	for (int j = 0; j < num_columns; j++)
	{
		if (bmaze[i][j] == 0)
			ft_putchar(f[1]);
		else if (bmaze[i][j] == 1)
			ft_putchar(f[0]);
		else
			ft_putchar(f[2]);
	}
	ft_putchar('\n');
    }
   // ft_print_bmatrix(bmaze, num_lines, num_columns);
    i = 0;
    while (i < num_lines)
    {
 	free(bmaze[i]);
 	free(maze[i]);
 	i++;   	
    }
    free(bmaze);
    free(maze);

    return 0;
}
