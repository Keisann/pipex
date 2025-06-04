# **************************************************************************** #
#                                 PIPEX MAKEFILE                               #
# **************************************************************************** #

NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f

# Paths
LIBFT_DIR   = libft
LIBFT_A     = $(LIBFT_DIR)/libft.a
INCLUDES    = -I$(LIBFT_DIR)/includes -I.

# Sources
SRC         = \
				pipex.c \
				pipex_utils.c

OBJ         = $(SRC:.c=.o)

# ANSI Colors
GREEN       = \033[1;32m
BLUE        = \033[1;34m
RED         = \033[1;31m
BOLD        = \033[1m
RESET       = \033[0m

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(LIBFT_A) $(NAME)

$(LIBFT_A):
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) > /dev/null
	@echo "$(GREEN)📚 Libft compilée avec succès.$(RESET)"

$(NAME): $(OBJ) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) -o $(NAME)
	@echo "$(GREEN)$(BOLD)🚀 pipex compilé avec succès !$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean > /dev/null
	@$(RM) $(OBJ)
	@echo
	@echo "$(BLUE)🧹 Objets nettoyés !$(RESET)"
	@echo

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean > /dev/null
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

