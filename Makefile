# BASIC
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
GDB = gdb

# TESTING
VAL = valgrind --leak-check=full --track-origin=yes
SANITIZE_THREAD = -fsanitize=thread
SANITIZE_ADDRESS = -fsanitize=address
HELGRIND = valgrind --tool=helgrind
DRD = valgrind --tool=drd

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
NAME =	minishell.a
SRCS =  minishell.c get_tokens.c exec_comand.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

# MAKE RULES
all: $(NAME) minishell

$(NAME): $(OBJS)
	@echo "$(GREEN)$(BOLD)Creating objects directory...$(RESET)"
	ar -rcs $(NAME) $(OBJS)
	@echo "$(GREEN)$(BOLD)Objects created!$(RESET)"
	
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

minishell: $(MINISHELL_OBJ) $(NAME)
	@echo "$(GREEN)$(BOLD)Creating executable...$(RESET)"
	$(CC) $(CFLAGS) $(MINISHELL_OBJ) $(NAME) -o minishell -lreadline
	@echo "$(GREEN)$(BOLD)Executable created!$(RESET)"

clean:
	@echo "$(YELLOW)$(BOLD)Removing objects...$(RESET)"
	$(RM) $(OBJSDIR)
	@echo "$(YELLOW)$(BOLD)Objects removed!$(RESET)"

fclean: clean
	@echo "$(RED)$(BOLD)Removing executable...$(RESET)"
	$(RM) minishell minishell.a
	@echo "$(RED)$(BOLD)Executable removed!$(RESET)"

re: fclean all
	@echo "$(GREEN)$(BOLD)Recompiled successfully!$(RESET)"

.SILENT: