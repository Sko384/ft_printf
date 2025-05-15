# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shmiyosh <shmiyosh@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025-05-12 17:31:35 by shmiyosh          #+#    #+#              #
#    Updated: 2025-05-12 17:31:35 by shmiyosh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a
CC 			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -f
SRCS	:= ft_printf.c ft_print_u.c ft_print_p.c ft_print_d.c ft_print_x.c
OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
