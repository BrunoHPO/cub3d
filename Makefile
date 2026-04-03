# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 09:52:57 by bolegari          #+#    #+#              #
#    Updated: 2026/04/03 15:06:12 by bolegari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS_NAME = cub3D_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
CPPFLAGS = -Iinclude -Iminilibx-linux -Ilibft_printf_gnl
BONUS_FLAGS = -DBONUS

RM = rm -f
RM_DIR = rm -rf
MKDIR = mkdir -p

MLX_FLAGS = -Lminilibx-linux -l:libmlx_Linux.a -L/usr/lib -I00minilibx-linux -lXext -lX11 -lm -lz
LIBFT_PATH = ./libft_printf_gnl
LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = src
OBJS_DIR = objs
BONUS_OBJS_DIR = objs_bonus

MAIN_SRC = $(SRC_DIR)/main.c

PARSER_SRC = \
	$(SRC_DIR)/parser/parse_file.c \
	$(SRC_DIR)/parser/parse_assets.c \
	$(SRC_DIR)/parser/parse_colour.c \
	$(SRC_DIR)/parser/handle_map.c \
	$(SRC_DIR)/parser/check_map.c \
	$(SRC_DIR)/parser/parse_utils.c \
	$(SRC_DIR)/parser/parse_debug.c

EXEC_COMMON_SRC = \
	$(SRC_DIR)/exec/graphics.c \
	$(SRC_DIR)/exec/init_execution.c \
	$(SRC_DIR)/exec/init_player.c \
	$(SRC_DIR)/exec/render_frame.c \
	$(SRC_DIR)/exec/key_press.c \
	$(SRC_DIR)/exec/key_release.c \
	$(SRC_DIR)/exec/raycast_draw.c \
	$(SRC_DIR)/exec/raycasting.c \

MANDATORY_SRC = \
	$(MAIN_SRC) \
	$(PARSER_SRC) \
	$(EXEC_COMMON_SRC) \
	$(SRC_DIR)/exec/movement_basic.c \
	$(SRC_DIR)/exec/movement_strafe.c \
	$(SRC_DIR)/exec/render_overlay.c \
	$(SRC_DIR)/exec/setup_hooks.c

BONUS_SRC = \
	$(MAIN_SRC) \
	$(PARSER_SRC) \
	$(EXEC_COMMON_SRC) \
	$(SRC_DIR)/exec/movement_basic.c \
	$(SRC_DIR)/bonus/mouse_look.c\
	$(SRC_DIR)/bonus/minimap.c\
	$(SRC_DIR)/bonus/minimap_helper.c \
	$(SRC_DIR)/exec/movement_strafe.c \
	$(SRC_DIR)/bonus/render_overlay.c \
	$(SRC_DIR)/bonus/setup_hooks.c

OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJS_DIR)/%.o,$(MANDATORY_SRC))
BONUS_OBJS = $(patsubst $(SRC_DIR)/%.c,$(BONUS_OBJS_DIR)/%.o,$(BONUS_SRC))

all: $(NAME)
	@echo "Build complete!"

bonus: $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX_FLAGS) $(LIBFT) -o $(BONUS_NAME)
	@echo "Bonus build complete!"

$(NAME): $(OBJS)
	@echo "Building libraries..."
	@$(MAKE) -sC ./libft_printf_gnl
	@$(MAKE) -sC ./minilibx-linux
	@echo "Linking cub3D executable..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling $<..."
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(BONUS_OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "Compiling bonus $<..."
	@$(MKDIR) $(@D)
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(BONUS_FLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@$(MAKE) clean -C ./libft_printf_gnl
	@$(MAKE) clean -C ./minilibx-linux
	@$(RM_DIR) $(OBJS_DIR)
	@$(RM_DIR) $(BONUS_OBJS_DIR)

fclean: clean
	@echo "Removing executable..."
	@$(MAKE) fclean -C ./libft_printf_gnl
	@$(RM) $(NAME)
	@$(RM) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
