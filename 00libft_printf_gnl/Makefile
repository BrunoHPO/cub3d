# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bolegari <bolegari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/17 11:08:47 by bolegari          #+#    #+#              #
#    Updated: 2025/10/15 12:01:41 by bolegari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CCFLAGS = -Wall -Wextra -Werror -fPIE
RM = rm -f

NAME = libft.a

ARNAME = ar rcs $(NAME)
RANNAME = ranlib $(NAME)

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstsize.c ft_lstnew.c ft_lstndelone.c ft_lstmap.c ft_lstlast.c ft_lstier.c ft_lstclear.c ft_lstadd_front.c ft_lstadd_back.c get_next_line_bonus.c
OBJ = $(SRC:.c=.o)

SRCPRINTF = $(addprefix ./01printf/, ft_printf.c print_char.c print_digit.c print_ptr.c print_str.c)
OBJPRINTF = $(SRCPRINTF:.c=.o)

all: $(NAME)

%.o: %.c
	@ $(CC) $(CCFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(OBJPRINTF)
	@ $(MAKE) --no-print-directory -C ./01printf
	@ $(ARNAME) $(OBJ) $(OBJPRINTF)
	@ $(RANNAME)

clean:
	@ $(MAKE) --no-print-directory clean -C ./01printf
	@ $(RM) $(OBJ)

fclean: clean
	@ $(RM) $(NAME)

re: fclean all
