# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:44:26 by jeguerin          #+#    #+#              #
#    Updated: 2023/12/29 15:57:27 by jeguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = convert_to_num.c handle_numbers.c  main.c push.c reverse_rotate.c \
	rotate.c swap.c utils.c set_lst.c radix_sort.c split.c free.c utils_2.c

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap

OBJS = $(SRCS:.c=.o)

all :	${NAME}

${NAME} : $(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
