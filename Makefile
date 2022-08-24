# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aruiz-mo <aruiz-mo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 16:12:16 by aruiz-mo          #+#    #+#              #
#    Updated: 2022/06/17 12:31:43 by aruiz-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

LIB		= libft.a

SRCS	= src/push_swap.c src/push_swap_utils.c src/push_swap_sfunctions.c\
src/push_swap_pfunctions.c src/push_swap_rerfunctions.c src/push_swap_rfunctions.c\
src/push_swap_sortfunctions.c src/push_swap_utils_2.c src/push_swap_sort_over_five.c\
src/push_swap_chunks_utils.c src/push_swap_chunks_utils_2.c

OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c
			$(CC) -c $(CFLAGS) -I include $< -o $(<:.c=.o)
all: $(NAME)

$(LIB):
			make -C libft/ all
			cp libft/libft.a $(LIB)

$(NAME):	$(OBJS) $(LIB)
			$(CC) -o $@ $^

clean:
				$(RM) $(NAME) $(OBJS)
				make -C libft/ clean

fclean: clean
				$(RM) $(NAME) $(LIB)
				make -C libft/ fclean

re:	fclean all

.PHONY: all clean fclean re