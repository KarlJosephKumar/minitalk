# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kakumar <kakumar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:28:21 by kakumar           #+#    #+#              #
#    Updated: 2023/03/20 13:35:32 by kakumar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
FLAGS = -Wall -Wextra -Werror
SRCS = server.c client.c
OBJS = $(SRCS:%.c=%.o)

.PHONY: all clean fclean re

all: $(SERVER) $(CLIENT)

$(SERVER): server.o libft/libft.a
			cc $(FLAGS) server.o libft/libft.a -o $(SERVER)

$(CLIENT): client.o libft/libft.a
			cc $(FLAGS) client.o libft/libft.a -o $(CLIENT)

%.o: %.c
		cc $(FLAGS) $< -I libft -c

libft/libft.a:
		$(MAKE) -C libft

clean:
		rm -f $(OBJS)
		$(MAKE) -C libft clean

fclean:	clean
		rm -f $(SERVER)
		rm -f $(CLIENT)
		$(MAKE) -C libft fclean
	
re: fclean all