# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:15:58 by alexandre         #+#    #+#              #
#    Updated: 2023/06/01 17:28:35 by jotavare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# BASIC
CC = cc -g
CSANI = cc -fsanitize=address
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
SRC =	source/commands/cd.c \
		source/commands/echo.c \
		source/commands/env.c \
		source/commands/exit.c \
		source/commands/export.c \
		source/commands/pwd.c \
		source/commands/unset.c \
		source/executer.c \
		source/expander.c \
		source/init.c \
		source/lexer.c \
		source/minishell.c \
		source/pipes.c \
		source/prompt.c \
		source/signals.c \
		source/start.c \
		source/tokens.c \
		source/heredocs.c \
		utilities/free.c \
		utilities/utilities.c \
		utilities/utilities_heredocs.c \

OBJSDIR = objects
OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

# MAKE RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Everything Done!"

sani: $(OBJ)
	$(MAKE) -C ./libft
	$(CSANI) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Compiled with fsanitizer"
	./$(NAME)

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE)	clean -C ./libft

fclean: clean
	$(RM) $(NAME) $(SANI) $(OBJSDIR)
	$(MAKE) fclean -C ./libft
	echo "Everything Deleted..."

re: fclean all
	
.SILENT:

.PHONY: all clean fclean re
