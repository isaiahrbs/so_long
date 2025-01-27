/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:45:15 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/24 13:15:46 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	parsemap(int fd, int lines)
{
	char	**grid;
	char	*line;
	int		i;

	grid = malloc(sizeof(char *) * (lines + 1));
	i = 0;
	while (i < lines)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		grid[i] = ft_strdup(line);
		free(line);
		i++;
	}
	grid[i] = NULL;
	if (!check_grid(grid))
	{
		free_grid(grid);
		return (0);
	}
	free_grid(grid);
	return (1);
}

int	process_file(char *argv, int lines)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		errormsg("Error opening file.");
		return (0);
	}
	if (!parsemap(fd, lines))
	{
		close(fd);
		errormsg("Failed to parse grid.");
		return (0);
	}
	close(fd);
	return (1);
}

int	count_lines(int fd)
{
	int		lines;
	char	*line;

	lines = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines++;
		free(line);
	}
	return (lines);
}

int	open_grid(char *argv)
{
	int	fd;
	int	lines;

	fd = open(argv, O_RDONLY);
	lines = count_lines(fd);
	if (lines <= 2)
	{
		errormsg("Invalid map.");
		close(fd);
		return (0);
	}
	if (!process_file(argv, lines))
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}
