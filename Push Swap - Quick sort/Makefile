# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeguerin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 10:44:26 by jeguerin          #+#    #+#              #
#    Updated: 2024/01/05 15:09:32 by jeguerin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./Source/convert_to_num.c ./Source/handle_numbers.c ./Source/main.c \
	./Source/push_swap.c ./Source/push.c ./Source/reverse_rotate.c \
	./Source/rotate.c ./Source/swap.c ./Source/utils.c ./Source/set_lst.c \
	./Source/split.c ./Source/free.c ./Source/utils_2.c ./Source/algo.c

BONUS = ./Bonus/checker.c ./Bonus/instructions.c \
	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	./Source/convert_to_num.c ./Source/handle_numbers.c ./Source/push_swap.c \
	./Source/push.c ./Source/reverse_rotate.c ./Source/rotate.c \
	./Source/swap.c ./Source/utils.c ./Source/set_lst.c ./Source/split.c \
	./Source/free.c ./Source/utils_2.c ./Source/algo.c

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
NAMEB = checker

OBJS = $(SRCS:.c=.o)
OBJSBONUS = $(BONUS:.c=.o)

all : author $(NAME)
bonus : author ${NAMEB}

author :
	@echo "Author :\tjeguerin\n"

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAMEB) : $(OBJSBONUS)
	$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAMEB)

clean :
	$(RM) $(OBJS) $(OBJSBONUS)

fclean : clean
	$(RM) $(NAME) $(NAMEB)

re : author fclean all

.PHONY: all clean fclean re bonus
