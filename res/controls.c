/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:37:19 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 12:36:33 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//controls are set inside of so_long.h
//control panel function for key calls
int	keyhook(int keycode, t_game *game)
{
	int	old_x;
	int	old_y;

	old_x = game->pxpos;
	old_y = game->pypos;
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		printf("Game Closed.\n");
		exit(0);
	}
	movements(keycode, game);
	if (old_x != game->pxpos || old_y != game->pypos)
	{
		can_i_exit(game);
		game->grid[old_y][old_x] = '0';
		game->grid[game->pypos][game->pxpos] = 'P';
		printf("Moves: %d\n", game->moves);
		draw_grid(game);
	}
	return (0);
}
