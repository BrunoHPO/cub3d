# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 11:08:47 by bolegari          #+#    #+#              #
#    Updated: 2025/10/14 18:49:30 by bolegari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = ft_printf.c print_char.c print_digit.c print_str.c print_ptr.c
OBJ = $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c
	@ $(CC) $(CCFLAGS) -c $< -o $@

clean:
	@ $(RM) $(OBJ)
