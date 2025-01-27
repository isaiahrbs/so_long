# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/10 16:14:24 by irobinso          #+#    #+#              #
#    Updated: 2025/01/27 13:08:47 by irobinso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRCDIR = res
OBJDIR = obj
INCDIR = inc
LIBFTDIR = libraries/libft
MLXDIR = libraries/minilibx-linux

# Source files
SRC = $(SRCDIR)/main.c \
      $(SRCDIR)/check_elems.c \
      $(SRCDIR)/check_grid.c \
      $(SRCDIR)/controls.c \
	  $(SRCDIR)/controls_utils.c \
      $(SRCDIR)/draw_grid.c \
      $(SRCDIR)/flood_grid.c \
      $(SRCDIR)/get_pos.c \
      $(SRCDIR)/load_grid.c \
      $(SRCDIR)/open_grid.c \
      $(SRCDIR)/textures.c \
	  $(SRCDIR)/utils.c


# Object files
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a

# Executable
NAME = so_long

# Include directories
INCLUDES = -I$(INCDIR) -I$(LIBFTDIR) -I$(MLXDIR)

# Linker flags
LDFLAGS = -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lbsd

# Rules
all: libft printf mlx $(NAME)

$(NAME): $(OBJ) $(MLX) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LDFLAGS) -o $@
	@echo "$(NAME) created successfully"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft"
	@$(MAKE) -C $(LIBFTDIR)

mlx: $(MLX)

$(MLX):
	@echo "Compiling minilibx"
	@$(MAKE) -C $(MLXDIR)

clean:
	rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@echo "Clean completed."

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@$(MAKE) -C $(MLXDIR) clean
	@echo "Full clean completed."

re: fclean all

.PHONY: all clean fclean re libft printf mlx
