# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:15:58 by alexandre         #+#    #+#              #
#    Updated: 2023/06/17 15:04:25 by jotavare         ###   ########.fr        #
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
SRC =	sources/minishell.c \
    	sources/commands/cd.c \
    	sources/commands/echo.c \
    	sources/commands/env.c \
    	sources/commands/exit.c \
    	sources/commands/export.c \
    	sources/commands/pwd.c \
    	sources/commands/unset.c \
    	sources/executer/executer.c \
    	sources/parser/expander.c \
    	sources/parser/lexer.c \
		sources/sanitize/signals.c \
    	sources/sanitize/free.c \
    	sources/tokens/count_tokens.c \
    	sources/tokens/get_tokens.c \
    	sources/tokens/tokens.c \
    	sources/initialize/init.c \
    	sources/initialize/start.c \
		sources/utilities/debugg.c \
    	sources/utilities/prompt.c \
    	sources/utilities/utilities.c \
		sources/tokens/get_tokens2.c \
		sources/error/error.c \

OBJSDIR = objects
OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

# MAKE RULES
all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(RLFLAG) -o $(NAME)
	echo "Everything Done!"

sani: re $(OBJ)
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

run: re
	./$(NAME)
	
.SILENT:

.PHONY: all clean fclean re
