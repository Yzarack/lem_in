# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/21 10:31:20 by jthierce          #+#    #+#              #
#    Updated: 2020/02/14 13:43:16 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_NAME =	ft_add_room.c\
			ft_lem_in.c\
			ft_rooms.c\
			ft_tools.c\
			ft_tools2.c\
			ft_tunnels.c\
			ft_rooms_tunnels.c\
			ft_resolve_karp.c\
			ft_tdjik_tools.c\
			ft_tdjik_tools2.c\
			ft_add_elem.c\
			ft_finish_djik.c\
			ft_print.c\
			ft_find_link.c\
			ft_resolve_karp_2.c\
			ft_count_end.c\
			ft_count_end_tools.c\
			ft_count_end_tools2.c\
			ft_endbfs.c\
			ft_print_tools.c\
			ft_print_tools_2.c

CC = gcc

CFLAGS = -Werror -Wextra -Wall

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = srcs/

OBJ_PATH = obj/

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

OBJ_FOLDER = obj

HEADER = -I includes/

LIBFT_PATH = libft/

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBFT) $(HEADER)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_FOLDER) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<

.PHONY: fclean all clean re

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C $(LIBFT_PATH)
	rm -rf $(NAME)

re:
	make fclean
	make all
