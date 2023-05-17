# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexfern <alexfern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:15:58 by alexandre         #+#    #+#              #
#    Updated: 2023/05/16 21:59:18 by alexfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RLFLAG = -lreadline
RM = rm -rf

# LIBFT
LIBFT = ./libft/libft.a

# COLORS
RESET			:= \033[0m
GREEN			=	\e[32m
CYAN			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m
RED				:= \033[1;31m
BOLD			:= \033[1;1m

# MINISHELL
NAME = minishell
SRC =	commands/cd.c \
		commands/echo.c \
		commands/env.c \
		commands/exit.c \
		commands/export.c \
		commands/pwd.c \
		commands/unset.c \
		source/get_tokens.c \
		source/lexer.c \
		source/minishell.c \
		source/signals.c \
		utilities/utilities.c \

OBJ = $(SRC:.c=.o)

# MAKE RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Everything Done!"

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE)	clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(OBJ)
	$(MAKE) fclean -C ./libft 
	echo "Everything Deleted..."

re: fclean all
	
.SILENT:

.PHONY: all clean fclean re