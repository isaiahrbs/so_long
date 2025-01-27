/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:12:51 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/24 13:04:14 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	getxpos(char **grid, char p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == p)
			{
				return (x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	getypos(char **grid, char p)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == p)
			{
				return (y);
			}
			x++;
		}
		y++;
	}
	return (0);
}
