# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nben-ais <nben-ais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 09:11:05 by nben-ais          #+#    #+#              #
#    Updated: 2023/10/17 14:41:34 by nben-ais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FILES = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c parsing_of_clrs_txtrs.c parsing.c parsing_of_map.c second_pasing.c
RM = rm -rf
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all