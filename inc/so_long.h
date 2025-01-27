/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:25:42 by irobinso          #+#    #+#             */
/*   Updated: 2025/01/27 13:07:29 by irobinso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <X11/keysym.h>
# include "../libraries/libft/inc/libft.h"
# include "../libraries/minilibx-linux/mlx.h"

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UARROW 111393
# define LARROW 111390
# define DARROW 111394
# define RARROW 111392
# define RED_CROSS 15

# define TILE_SIZE 64
# define MAX_MAP_WIDTH 100
# define MAX_MAP_HEIGHT 100

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*collectibles;
	void	*floor;
	void	*exit;
}	t_textures;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**grid;
	int			tiles_size;
	int			moves;
	int			pxpos;
	int			pypos;
	int			expos;
	int			eypos;
	int			coins;
	int			visc;
	int			vise;
	int			ce;
	int			cp;
	int			cc;
	int			len;
	int			hei;
	t_textures	textures;
}	t_game;

int		open_grid(char *argv);
int		check_grid(char **grid);
int		load_grid(char **argv, t_game *game);
int		flood_grid(t_game *game);
int		check_elems(t_game *game);
void	errormsg(char *msg);
void	free_grid(char **grid);
int		keyhook(int keycode, t_game *game);
int		getxpos(char **grid, char c);
int		getypos(char **grid, char c);
void	load_textures(t_game *game);
void	draw_grid(t_game *game);
int		count_lines(int fd);
int		count_coins(char **grid);
void	set_values(t_game *game);
void	movements(int keycode, t_game *game);
void	can_i_exit(t_game *game);

#endif
