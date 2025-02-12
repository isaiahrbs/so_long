/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:23:58 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 15:19:47 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	printf_map(char **grid)
{
	int	i;
	int	j;

	if (!grid)
	{
		printf("Error: Grid is NULL\n\n");
		return ;
	}
	i = 0;
	while (grid[i])
	{
		j = 0;
		while (grid[i][j])
		{
			printf("%c", grid[i][j]);
			fflush(stdout);
			usleep(10000);
			j++;
		}
		if (grid[i][j - 1] != '\n')
			printf("\n");
		i++;
	}
	printf("\n");
}

int	close_window(void *param)
{
	(void)param;
	printf("Game Closed.\n");
	exit(0);
}

int	create_game(t_game game)
{
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		free_grid(game.grid);
		return (1);
	}
	game.win = mlx_new_window(game.mlx, game.len * TILE_SIZE,
			game.hei * TILE_SIZE, "So_long");
	if (!game.win)
	{
		free_grid(game.grid);
		mlx_destroy_display(game.mlx);
		free(game.mlx);
		return (1);
	}
	load_textures(&game);
	draw_grid(&game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_hook(game.win, 2, 1L << 0, keyhook, &game);
	mlx_loop(game.mlx);
	printf("Steps: %d\n", game.moves);
	free_grid(game.grid);
	return (0);
}

int	handle_args(int argc, char **argv)
{
	if (argc < 2)
	{
		errormsg("Please provide a map file");
		return (0);
	}
	else if (argc > 2)
	{
		errormsg("Too many arguments");
		return (0);
	}
	ft_printf("- Map file: %s\n\n", argv[1]);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	memset(&game, 0, sizeof(t_game));
	if (!handle_args(argc, argv))
		return (1);
	if (!open_grid(argv[1]))
		return (1);
	if (!load_grid(argv, &game))
		return (0);
	printf_map(game.grid);
	if (!flood_grid(&game))
		return (0);
	if (create_game(game))
		return (1);
	return (0);
}
