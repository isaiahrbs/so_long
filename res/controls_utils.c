/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:00:17 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 11:05:25 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move_up(t_game *game)
{
	t_game	*tmp;

	tmp = game;
	if (tmp->grid[tmp->pypos - 1][tmp->pxpos] == '0'
	|| tmp->grid[tmp->pypos - 1][tmp->pxpos] == 'C'
	|| tmp->grid[tmp->pypos - 1][tmp->pxpos] == 'E')
	{
		if (tmp->grid[tmp->pypos - 1][tmp->pxpos] == 'C')
			game->coins--;
		game->pypos -= 1;
		game->moves++;
		if (game->pxpos == game->expos && game->pypos == game->eypos
			&& game->coins == 0)
		{
			printf("You win!\n");
			exit(0);
		}
	}
}

void	move_down(t_game *game)
{
	t_game	*tmp;

	tmp = game;
	if (tmp->grid[tmp->pypos + 1][tmp->pxpos] == '0'
	|| tmp->grid[tmp->pypos + 1][tmp->pxpos] == 'C'
	|| tmp->grid[tmp->pypos + 1][tmp->pxpos] == 'E')
	{
		if (tmp->grid[tmp->pypos + 1][tmp->pxpos] == 'C')
			game->coins--;
		game->pypos += 1;
		game->moves++;
		if (game->pxpos == game->expos && game->pypos == game->eypos
			&& game->coins == 0)
		{
			printf("You win!\n");
			exit(0);
		}
	}
}

void	move_left(t_game *game)
{
	t_game	*tmp;

	tmp = game;
	if (tmp->grid[tmp->pypos][tmp->pxpos - 1] == '0'
	|| tmp->grid[tmp->pypos][tmp->pxpos - 1] == 'C'
	|| tmp->grid[tmp->pypos][tmp->pxpos - 1] == 'E')
	{
		if (tmp->grid[tmp->pypos][tmp->pxpos - 1] == 'C')
			game->coins--;
		game->pxpos -= 1;
		game->moves++;
		if (game->pxpos == game->expos && game->pypos == game->eypos
			&& game->coins == 0)
		{
			printf("You win!\n");
			exit(0);
		}
	}
}

void	move_right(t_game *game)
{
	t_game	*tmp;

	tmp = game;
	if (tmp->grid[tmp->pypos][tmp->pxpos + 1] == '0'
	|| tmp->grid[tmp->pypos][tmp->pxpos + 1] == 'C'
	|| tmp->grid[tmp->pypos][tmp->pxpos + 1] == 'E')
	{
		if (tmp->grid[tmp->pypos][tmp->pxpos + 1] == 'C')
			game->coins--;
		game->pxpos += 1;
		game->moves++;
		if (game->pxpos == game->expos && game->pypos == game->eypos
			&& game->coins == 0)
		{
			printf("You win!\n");
			exit(0);
		}
	}
}

void	movements(int keycode, t_game *game)
{
	if (keycode == W)
		move_up(game);
	if (keycode == S)
		move_down(game);
	if (keycode == A)
		move_left(game);
	if (keycode == D)
		move_right(game);
}
