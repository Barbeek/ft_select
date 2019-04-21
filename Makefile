# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pespalie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/01 01:07:20 by pespalie          #+#    #+#              #
#    Updated: 2018/10/10 22:11:37 by pespalie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
NAME =	ft_select

SRC_NAME = main.c get_longest_word_len.c save_env.c refresh_screen.c\
	   print_words.c input_loop.c exit.c reduce_env.c
SRC_PATH = ./src/
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(SRC:.c=.o)
LIBFTD	= ./includes/libft
LDFLAGS	= -Wall -Wextra -Werror -g -I$(LIBFTD)
LDLIBS	= -L$(LIBFTD) -lft -ltermcap

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTD)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(LDFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make -C $(LIBFTD) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTD) fclean

re: fclean all
