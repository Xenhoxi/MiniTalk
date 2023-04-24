# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/23 02:03:14 by ljerinec          #+#    #+#              #
#    Updated: 2023/04/23 02:33:30 by ljerinec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME     := client
PRINT_PREFIX	= \033[1m\033[38;5;240m[\033[0m\033[38;5;250m$(NAME)\033[1m\033[38;5;240m] \033[38;5;105m~\033[0m

SRCS_CLIENT =	sources/client.c \

SRCS_SERVER = sources/server.c \

OBJS_CLIENT := $(SRCS_CLIENT:%.c=%.o)
OBJS_SERVER := $(SRCS_SERVER:%.c=%.o)

FLAGS    = -Wall -Wextra -Werror -g3
CC       = gcc $(FLAGS)

FT_PRINTF_DIR = includes/ft_printf/ft_printf.a

all: $(NAME)

$(NAME): $(OBJS_CLIENT) $(OBJS_SERVER)
	@make -C includes/ft_printf
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Compiling \033[0m\n"
	@$(CC) -o client $(OBJS_CLIENT) $(FT_PRINTF_DIR)
	@$(CC) -o server $(OBJS_SERVER) $(FT_PRINTF_DIR)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

clean:
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Cleaning \033[0m\n"
	@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)
	@echo "$(PRINT_PREFIX)\033[0;38;5;226m Done \033[0m\n"

fclean: clean
	@rm -f server
	@rm -f client

re: fclean all

.PHONY: all clean fclean re bonus