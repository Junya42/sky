# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarouf <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 02:59:13 by cmarouf           #+#    #+#              #
#    Updated: 2021/12/15 16:31:32 by anremiki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/main.c			  \
	   srcs/destroy.c		  \
	   srcs/game.c			  \
	   srcs/utilsbis.c		  \
	   srcs/ia.c			  \
	   srcs/free.c			  \
	   srcs/ft_itoa.c		  \
	   srcs/core.c			  \
	   srcs/input.c			  \
	   srcs/filecheck.c		  \
	   srcs/init_map_player.c \
	   srcs/parsing.c		  \
	   srcs/print.c			  \
	   srcs/utils.c			  \

OBJS = ${SRCS:.c=.o}

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = ./minilibx/libmlx_Linux.a -lXext -lX11 -I ./minilibx/ 

NAME = so_long

CC = gcc

B = 0

ifdef BONUS
B = 1
endif
.c.o:
	${CC} -D B=$(B) -I includes ${CFLAGS} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
		$(RM) ${OBJS}
		make clean -C ./minilibx

fclean: clean
		$(RM) $(NAME)
		$(RM) ./minilibx/libmlx_Linux.a
		$(RM) ./minilibx/libmlx.a
re:	fclean all

bonus: fclean
	$(MAKE) BONUS=1

.PHONY: all clean fclean re bonus
