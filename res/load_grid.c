/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:54:33 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 13:01:18 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//check if the map's lines are equal
int	map_size(t_game *game)
{
	int	len;
	int	i;
	int	nextlen;

	i = 0;
	while (game->grid[i + 1] != NULL)
	{
		len = ft_strlen(game->grid[i]);
		nextlen = ft_strlen (game->grid[i + 1]);
		if (game->grid[i][len - 1] == '\n')
			len--;
		if (game->grid[i + 1][nextlen - 1] == '\n')
			nextlen--;
		if (len != nextlen)
		{
			return (0);
		}
		i++;
	}
	len = ft_strlen(game->grid[0]);
	if (game->grid[0][len - 1] == '\n')
		len--;
	game->len = len;
	game->hei = i + 1;
	return (1);
}

//fill the line with strdup, strdup mallocs a new string with the same
// content as the string passed as argument
int	read_and_store_line(t_game *game, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (-1);
	game->grid[i] = ft_strdup(line);
	free(line);
	if (game->grid[i] == NULL)
	{
		errormsg("Error: duplicating line.\n\n");
		return (0);
	}
	return (1);
}

//loop that calls the read_and_store_line function that
// adds a line to the grid until the end
int	fill_grid(t_game *game, int fd, int lines)
{
	int	i;
	int	result;

	i = 0;
	while (i < lines)
	{
		result = read_and_store_line(game, fd, i);
		if (result == -1)
			break ;
		if (result == 0)
		{
			free_grid(game->grid);
			close(fd);
			return (0);
		}
		i++;
	}
	game->grid[i] = NULL;
	close(fd);
	return (1);
}

//malloc the grid with 4 strings then i call the fill grid function
int	malloc_grid(t_game *game, int fd, int lines)
{
	game->grid = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!game->grid)
	{
		close(fd);
		errormsg("Error: malloc grid.");
		return (0);
	}
	if (!fill_grid(game, fd, lines))
	{
		free_grid(game->grid);
		errormsg("Error: fill_grid.");
		return (0);
	}
	return (1);
}

//main function to call the other functions
int	load_grid(char **argv, t_game *game)
{
	int	fd;
	int	lines;

	fd = open(argv[1], O_RDONLY);
	lines = count_lines(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	if (!malloc_grid(game, fd, lines))
	{
		close(fd);
		errormsg("Error: fill_grid.");
		return (0);
	}
	if (!map_size(game))
	{
		errormsg("Error: map_size.");
		free_grid(game->grid);
		return (0);
	}
	set_values(game);
	return (1);
}
