# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:44:26 by jeguerin          #+#    #+#              #
#    Updated: 2023/12/04 12:00:30 by jeguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = algorithm.c count_strokes.c handle_numbers.c index.c main.c push.c /
		reverse_rotate.c rotate.c swap.c utils.c


CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap.a

OBJS = $(SRCS:.c=.o)

all :	${NAME}

${NAME} : $(OBJS)
		ar -rcs -o $(NAME) $(OBJS)


clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re
