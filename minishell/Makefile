# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotavare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 15:15:58 by alexandre         #+#    #+#              #
#    Updated: 2023/06/20 06:59:02 by jotavare         ###   ########.fr        #
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
		sources/error/error_1.c \
		sources/error/error_2.c \
		sources/error/error_3.c \
    	sources/executer/executer.c \
		sources/executer/paths.c \
		sources/executer/pipes.c \
		sources/executer/redirects.c \
    	sources/parser/expander.c \
    	sources/parser/lexer.c \
		sources/parser/parser.c \
		sources/sanitize/signals.c \
    	sources/sanitize/free_1.c \
		sources/sanitize/free_2.c \
    	sources/tokens/count_tokens.c \
    	sources/tokens/get_tokens.c \
    	sources/tokens/tokens.c \
		sources/initialize/check.c \
    	sources/initialize/init.c \
		sources/initialize/refresh.c \
    	sources/initialize/start.c \
		sources/utilities/debugg.c \
    	sources/utilities/prompt.c \
    	sources/utilities/utils_1.c \
		sources/utilities/utils_2.c \
		sources/tokens/get_tokens2.c \

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
