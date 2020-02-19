# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 11:01:42 by lufrar            #+#    #+#              #
#    Updated: 2020/02/14 01:03:44 by jthierce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror -g -c
NAME = libft.a
OBJ = $(SRCS:.c=.o)

SRCS = ft_strdup.c \
		ft_strlen.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strlcat.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_atoi.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_bzero.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_sqrt.c \
		ft_isprime.c \
		ft_find_next_prime.c \
		ft_recursive_factorial.c \
		ft_recursive_power.c \
		ft_puttab.c \
		ft_puttab_int.c \
		ft_get_nb_words.c \
		ft_getnb.c \
		ft_word_size.c \
		ft_int_len.c \
		ft_iterative_power.c \
		ft_get_next_line.c \
		ft_split_whitespaces.c \
		ft_abs.c \
		ft_min.c \
		ft_strchrint.c \
		ft_strjoinendl.c \
		ft_strjoinfree.c \
		ft_tabdup.c


all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(FLAGS) $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all
