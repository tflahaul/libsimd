# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thflahau <thflahau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/11 10:35:03 by thflahau          #+#    #+#              #
#    Updated: 2019/07/23 13:36:55 by thflahau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc

NAME		=	libsimd.a

CFLAGS		=	-Wall				\
				-Wextra				\
				-Werror				\
				-msse4				\
				-O3					\
				-c

include		libsources.mk

OBJDIR	=	objs

OBJS	=	$(LIBSOURCES:.c=.o)

OBJPATH	=	$(addprefix $(OBJDIR)/, $(LIBSOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@ar -cq $@ $(OBJPATH)
	@ranlib $@

%.o: %.c	libsimd.h
	$(CC) $(CFLAGS) $< -o $(OBJDIR)/$@

clean:
	@/bin/rm -rf $(OBJDIR)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.silent: all clean fclean $(NAME)
.phony: $(NAME) clean fclean re
