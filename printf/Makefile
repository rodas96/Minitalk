# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmorais <rmorais@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 18:11:46 by rmorais           #+#    #+#              #
#    Updated: 2022/11/29 15:12:12 by rmorais          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printchar ft_printnbrbase ft_printstr ft_printf ft_strlen \

OBJS =	$(SRCS:=.o)

CC = gcc
RM = rm -f

all: $(NAME)

$(NAME): $(SRCS:=.o)
				@ar rcs $(NAME) $(SRCS:=.o)
bonus:	$(SRCS:=.o)	
				@ar rcs $(NAME) $(SRCS:=.o)
clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)