# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/14 09:52:57 by bolegari          #+#    #+#              #
#    Updated: 2026/03/15 21:16:32 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CCFLAGS = -Wall -Wextra -Werror -O3
CCINCLUDES = -Iinclude -I00minilibx-linux -I00libft_printf_gnl

RM = rm -f
RM_DIR = rm -rf
DIR_DUP = mkdir -p $(@D)

MLX_FLAGS = -L00minilibx-linux -l:libmlx_Linux.a -L/usr/lib -I00minilibx-linux -lXext -lX11 -lm -lz
LIBFT_PATH = ./00libft_printf_gnl
LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = src
OBJS_DIR = objs
INC_DIR = include

MAIN_SRC = main.c
MAIN_SRC := $(addprefix $(SRC_DIR)/,$(MAIN_SRC))

PARSER_DIR = $(SRC_DIR)/parser
PARSER_SRC = \
	parse_file.c \
	parse_assets.c \
	parse_colour.c \
	handle_map.c \
	check_map.c \
	parse_utils.c \
	parse_debug.c
PARSER_SRC := $(addprefix $(PARSER_DIR)/,$(PARSER_SRC))

SRCS := $(MAIN_SRC) $(PARSER_SRC)
OBJS := $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)
	@echo "Build complete!"

$(NAME): $(OBJS)
		@echo "Building libraries..."
		@$(MAKE) -sC ./00libft_printf_gnl
		@$(MAKE) -sC ./00minilibx-linux
		@echo "Linking cub3D executable..."
		@$(CC) $(CCFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: %.c
		@echo "Compiling $<..."
		@$(DIR_DUP)
		@$(CC) $(CCFLAGS) $(CCINCLUDES) -c $< -o $@

clean:
		@echo "Cleaning object files..."
		@$(MAKE) clean -C ./00libft_printf_gnl
		@$(MAKE) clean -C ./00minilibx-linux
		@$(RM_DIR) $(OBJS_DIR) 

fclean: clean
		@echo "Removing executable..."
		@$(MAKE) fclean -C ./00libft_printf_gnl
		@$(RM) $(NAME)
		
re: fclean all

.PHONY: all clean fclean re
