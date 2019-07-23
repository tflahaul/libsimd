# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 10:35:03 by thflahau          #+#    #+#              #
#    Updated: 2019/07/23 14:21:52 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		=	libsimd.a

CFLAGS		=	-Wall				\
				-Wextra				\
				-Werror				\
				-pedantic			\
				-msse4				\
				-O3					\
				-c

include		libsources.mk

OBJS	=	$(LIBSOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar -cq $@ $(OBJS)
	@ranlib $@

%.o: %.c	libsimd.h
	$(CC) $(CFLAGS) $<

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.silent: all clean fclean $(NAME)
.phony: $(NAME) clean fclean re
