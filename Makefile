# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pstevens <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/01 15:38:04 by pstevens          #+#    #+#              #
#    Updated: 2016/11/05 11:57:47 by pstevens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fillit

SRCS		=	main.c \
				piece_init.c \
				validate.c \
				map.c \
				tetriminos.c \
				solve.c

OBJS		=	$(addprefix $(OBJSDIR), $(SRCS:.c=.o))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	./libft/libft.a
LIBINCL		=	-I ./libft/
LIBLINK		=	-L ./libft -lft

SRCSDIR		=	./srcs/
INCLDIR		=	./includes/
OBJSDIR		=	./objs/

all: objs libft $(NAME)

objs:
	mkdir -p $(OBJSDIR)

$(OBJSDIR)%.o: $(SRCSDIR)%.c
	$(CC) $(CFLAGS) $(LIBINCL) -I $(INCLDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJSDIR)
	make clean -C ./libft

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re libft
