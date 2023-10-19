# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/16 12:47:01 by marvin            #+#    #+#              #
#    Updated: 2023/10/16 12:47:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.o

%.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@
	
all: $(NAME)

$(NAME): $(SRCS)
	ar rc $(NAME) $(SRCS)

clean:
	$(RM) $(SRCS)

fclean: clean
	$(RM) $(NAME)

re: fclean all