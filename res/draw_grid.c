/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:33:43 by irobinso          #+#    #+#             */
/*   Updated: 2024/12/17 10:05:06 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*search_textures(char tile, t_textures *textures)
{
	if (tile == '1')
		return (textures->wall);
	else if (tile == 'P')
		return (textures->player);
	else if (tile == 'C')
		return (textures->collectibles);
	else if (tile == 'E')
		return (textures->exit);
	else if (tile == '0')
		return (textures->floor);
	return (NULL);
}

void	draw_grid(t_game *game)
{
	int		y;
	int		x;
	void	*img_to_draw;

	y = 0;
	game->tiles_size = TILE_SIZE;
	img_to_draw = NULL;
	while (game->grid[y])
	{
		x = 0;
		while (game->grid[y][x])
		{
			img_to_draw = search_textures(game->grid[y][x], &game->textures);
			if (img_to_draw)
				mlx_put_image_to_window(game->mlx, game->win, img_to_draw,
					x * game->tiles_size, y * game->tiles_size);
			x++;
		}
		y++;
	}
}
