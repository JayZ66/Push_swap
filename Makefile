# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:44:26 by jeguerin          #+#    #+#              #
#    Updated: 2023/11/16 10:50:00 by jeguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = push_swap.c instructions.c


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
