/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:56:35 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 10:59:06 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	validate_grid(char **grid)
{
	int	i;
	int	j;

	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (!(grid[i][j] == '1' || grid[i][j] == '0' ||
				grid[i][j] == 'C' || grid[i][j] == 'P' ||
				grid[i][j] == 'E' || grid[i][j] == '\n'))
			{
				printf("Error: Invalid character in grid: %c\n", grid[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	walls(char **grid, int last)
{
	int	i;
	int	len;

	len = ft_strlen(grid[0]);
	i = 1;
	while (i < last)
	{
		if (grid[i][0] != '1' || grid[i][len - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

//checking each character of botton and top line to be '1's
int	top_bottom(char **grid, int last)
{
	int	width;

	width = 0;
	while (grid[0][width] && grid[last][width])
	{
		if (grid[0][width] != '1' || grid[last][width] != '1')
			return (0);
		width++;
	}
	return (1);
}

int	check_grid(char **grid)
{
	int	last_line;

	last_line = 0;
	while (grid[last_line])
		last_line++;
	last_line--;
	while (grid[last_line][0] == '\n')
		last_line--;
	if (!top_bottom(grid, last_line))
	{
		errormsg("Invalid top or bottom line.");
		return (0);
	}
	if (!walls(grid, last_line))
	{
		errormsg("Invalid walls.");
		return (0);
	}
	if (!validate_grid(grid))
	{
		errormsg("Invalid grid content.");
		return (0);
	}
	return (1);
}
