# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyean-wa <yyean-wa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 22:27:23 by yyean-wa          #+#    #+#              #
#    Updated: 2024/08/02 23:41:05 by yyean-wa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I./

SERVER = server.c
CLIENT = client.c
LIB = libft/libft.a
REMOVE = rm -rf

SERVER_SRC = $(SERVER)
SERVER_OBJS = $(SERVER_SRC:.c=.o)
CLIENT_SRC = $(CLIENT)
CLIENT_OBJS = $(CLIENT_SRC:.c=.o)
OBJS =	$(SERVER_OBJS)\
		$(CLIENT_OBJS)

all:$(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): _libft $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) $(INCLUDE) $(LIB) -o $(CLIENT_NAME)

$(SERVER_NAME): _libft $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) $(INCLUDE) $(LIB) -o $(SERVER_NAME)

_libft:
	@make -C libft/

clean :
	@make clean -C libft/
	@$(REMOVE) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean :clean
	@make fclean -C libft/
	@$(REMOVE) $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
