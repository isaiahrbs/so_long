/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:46:10 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 10:57:59 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	count_elem_in_line(char *line, t_game *game)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] == 'E')
			game->ce++;
		else if (line[j] == 'P')
			game->cp++;
		else if (line[j] == 'C')
			game->cc++;
		j++;
	}
}

void	count_elem_in_grid(char **grid, t_game *game)
{
	int	i;

	i = 0;
	while (grid[i])
	{
		count_elem_in_line(grid[i], game);
		i++;
	}
}

int	check_elems(t_game *game)
{
	game->cc = 0;
	game->ce = 0;
	game->cp = 0;
	count_elem_in_grid(game->grid, game);
	if (game->ce != 1 || game->cp != 1 || game->cc < 1)
	{
		free_grid(game->grid);
		errormsg("There is more than one player spawn");
		return (0);
	}
	printf("ce = %d\n", game->ce);
	printf("cp = %d\n", game->cp);
	printf("cc = %d\n", game->cc);
	return (1);
}
