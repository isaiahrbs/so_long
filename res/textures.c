/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:25:56 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 13:05:05 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	free_textures(t_game *game)
{
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.collectibles)
		mlx_destroy_image(game->mlx, game->textures.collectibles);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
}

void	load_textures(t_game *game)
{
	int	img_width;
	int	img_height;

	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/0_floor.xpm", &img_width, &img_height);
	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/1_wall.xpm", &img_width, &img_height);
	game->textures.collectibles = mlx_xpm_file_to_image(game->mlx,
			"./textures/C_collect.xpm", &img_width, &img_height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/E_exit.xpm", &img_width, &img_height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"./textures/P_player.xpm", &img_width, &img_height);
	if (!game->textures.floor || !game->textures.wall
		|| !game->textures.collectibles || !game->textures.exit
		|| !game->textures.player)
	{
		errormsg("Error loading textures");
		free_textures(game);
		exit(1);
	}
}
