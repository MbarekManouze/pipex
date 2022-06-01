# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 15:49:48 by mmanouze          #+#    #+#              #
#    Updated: 2022/04/16 15:51:32 by mmanouze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = ft_close_dup.c \
ft_error.c \
ft_split.c \
ft_strjoin.c \
pipex.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -f ${OBJS} ${OBJS_BONUS}

fclean:    clean
	rm -f ${NAME} ${BONUS}

re:    fclean all

.PHONY: all clean fclean re