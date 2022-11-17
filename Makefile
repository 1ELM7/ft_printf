# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmendez <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 11:22:07 by jmendez           #+#    #+#              #
#    Updated: 2022/11/10 14:45:46 by jmendez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = put.c\
	  len.c \
	  ft_atoi.c\
	  ft_isdigit.c\
	  ft_print_p.c  \
	  print_hexa.c	 \
	  print_letters.c \
	  print_numbers.c  \
	  ft_print_percent.c\
	  ft_printf.c \
	  ft_find_arg.c\
	  ft_type_arg.c \
	  bonus.c 		 \


OBJ = ${SRC:.c=.o}

CFLAG = -Wall -Werror -Wextra

CC = clang

.c.o:
	@gcc ${CFLAG} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ}
	@ar rc ${NAME} ${OBJ}
	@printf "libftprintf.a is compiled\n"

all: ${NAME}
	@printf "libftprintf.a is compiled\n"
bonus: all

clean:
	@rm -f ${OBJ}
	@printf "ft_printf.h is clean and still got libftprintf.a\n"

fclean: clean
	@rm -f ${NAME}
	@printf "ft_printf.h is all clean\n"

re: fclean all
	@printf "ft_printf.h cleaned and compiled again libftprintf.a\n"

.PHONY : all clean fclean re bonus