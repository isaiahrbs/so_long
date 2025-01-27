/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:07:31 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 13:05:18 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	can_i_exit(t_game *game)
{
	if (game->coins == 0)
	{
		game->grid[game->eypos][game->expos] = 'E';
	}
	else if (game->grid[game->eypos][game->expos] == 'P')
	{
		game->grid[game->eypos][game->expos] = 'P';
	}
	else
	{
		game->grid[game->eypos][game->expos] = '0';
	}
}

void	set_values(t_game *game)
{
	game->vise = 0;
	game->visc = 0;
	game->pypos = getypos(game->grid, 'P');
	game->pxpos = getxpos(game->grid, 'P');
	game->eypos = getypos(game->grid, 'E');
	game->expos = getxpos(game->grid, 'E');
	game->coins = count_coins(game->grid);
}

//goes through the map and counts how many Coins there is.
int	count_coins(char **grid)
{
	int	x;
	int	y;
	int	coins;

	x = 0;
	y = 0;
	coins = 0;
	while (grid[y])
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C')
				coins++;
			x++;
		}
		y++;
	}
	return (coins);
}

void	errormsg(char *msg)
{
	ft_printf("\e[31m\e[1mError!\n%s\e[0m \n", msg);
}

void	free_grid(char **grid)
{
	int	i;

	if (!grid)
		return ;
	i = 0;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
