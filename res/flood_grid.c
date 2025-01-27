/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:10:39 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 13:00:18 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_errors(t_game *game)
{
	if (game->expos < 0 || game->expos >= game->len
		|| game->eypos < 0 || game->eypos >= game->hei)
	{
		errormsg("Exit position out of bounds.");
		return (0);
	}
	return (1);
}

void	print_game_stats(t_game *game)
{
	int	x;
	int	y;

	x = getxpos(game->grid, 'P');
	y = getypos(game->grid, 'P');
	printf("Player x position: %d\n", x);
	usleep(100000);
	printf("Player y position: %d\n", y);
	usleep(100000);
	printf("Exit x position: %d\n", game->expos);
	usleep(100000);
	printf("Exit y position: %d\n", game->eypos);
	usleep(100000);
	printf("Game length: %d\n", game->len);
	usleep(100000);
	printf("Game height: %d\n", game->hei);
	usleep(100000);
	printf("Coins: %d\n\n", game->coins);
	usleep(200000);
}

void	fill_back(t_game *game, int x, int y)
{
	if (!game->grid[y] || !game->grid[y][x]
		|| (game->grid[y][x] != 'F' && game->grid[y][x] != 'T'
		&& game->grid[y][x] != 'E'))
		return ;
	if (game->grid[y][x] == 'T')
		game->grid[y][x] = 'C';
	else if (game->grid[y][x] == 'F' || game->grid[y][x] == 'E')
		game->grid[y][x] = '0';
	fill_back(game, x + 1, y);
	fill_back(game, x - 1, y);
	fill_back(game, x, y + 1);
	fill_back(game, x, y - 1);
}

void	fill(t_game *game, int x, int y)
{
	if (y < 0 || y >= game->hei || x < 0 || x >= game->len)
	{
		printf("Out of bounds: x=%d, y=%d\n", x, y);
		return ;
	}
	if (!game->grid[y] || !game->grid[y][x]
		|| (game->grid[y][x] != '0' && game->grid[y][x] != 'E'
		&& game->grid[y][x] != 'C' && game->grid[y][x] != 'P'))
		return ;
	if (game->grid[y][x] == 'E')
	{
		game->grid[y][x] = '0';
		game->vise++;
	}
	else if (game->grid[y][x] == 'C')
	{
		game->visc++;
		game->grid[y][x] = 'T';
	}
	else
		game->grid[y][x] = 'F';
	fill(game, x + 1, y);
	fill(game, x - 1, y);
	fill(game, x, y + 1);
	fill(game, x, y - 1);
}

int	flood_grid(t_game *game)
{
	game->pxpos = getxpos(game->grid, 'P');
	game->pypos = getypos(game->grid, 'P');
	print_game_stats(game);
	if (!check_errors(game))
		return (0);
	game->grid[game->eypos][game->expos] = 'E';
	if (!check_elems(game))
		return (0);
	fill(game, game->pxpos, game->pypos);
	if (game->visc != game->coins || game->vise != 1)
	{
		free_grid(game->grid);
		return (0);
	}
	fill_back(game, game->pxpos, game->pypos);
	game->grid[game->pypos][game->pxpos] = 'P';
	return (1);
}
