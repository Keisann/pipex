# **************************************************************************** #
#                                  MAKEFILE                                    #
# **************************************************************************** #

NAME        := libft.a
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
AR          := ar rcs
RM          := rm -f
MKDIR       := mkdir -p

INCLUDES    := -Iincludes
OBJ_DIR     := objs

# ANSI Colors
GREEN       := \033[1;32m
BLUE        := \033[1;34m
RED         := \033[1;31m
BOLD        := \033[1m
RESET       := \033[0m

SRC := \
	srcs/ft/fonctions/ft_atoi.c \
	srcs/ft/fonctions/ft_bzero.c \
	srcs/ft/fonctions/ft_calloc.c \
	srcs/ft/fonctions/ft_isalnum.c \
	srcs/ft/fonctions/ft_isalpha.c \
	srcs/ft/fonctions/ft_isascii.c \
	srcs/ft/fonctions/ft_isdigit.c \
	srcs/ft/fonctions/ft_isprint.c \
	srcs/ft/fonctions/ft_itoa.c \
	srcs/ft/fonctions/ft_memchr.c \
	srcs/ft/fonctions/ft_memcmp.c \
	srcs/ft/fonctions/ft_memcpy.c \
	srcs/ft/fonctions/ft_memmove.c \
	srcs/ft/fonctions/ft_memset.c \
	srcs/ft/fonctions/ft_split.c \
	srcs/ft/fonctions/ft_strchr.c \
	srcs/ft/fonctions/ft_strdup.c \
	srcs/ft/fonctions/ft_striteri.c \
	srcs/ft/fonctions/ft_strjoin.c \
	srcs/ft/fonctions/ft_strlcat.c \
	srcs/ft/fonctions/ft_strlcpy.c \
	srcs/ft/fonctions/ft_strlen.c \
	srcs/ft/fonctions/ft_strmapi.c \
	srcs/ft/fonctions/ft_strncmp.c \
	srcs/ft/fonctions/ft_strnstr.c \
	srcs/ft/fonctions/ft_strrchr.c \
	srcs/ft/fonctions/ft_strtrim.c \
	srcs/ft/fonctions/ft_substr.c \
	srcs/ft/fonctions/ft_tolower.c \
	srcs/ft/fonctions/ft_toupper.c \
	srcs/ft/fd/ft_putchar_fd.c \
	srcs/ft/fd/ft_putendl_fd.c \
	srcs/ft/fd/ft_putnbr_fd.c \
	srcs/ft/fd/ft_putstr_fd.c \
	srcs/gnl/get_next_line.c \
	srcs/gnl/get_next_line_utils.c \
	srcs/printf/ft_printf.c \
	srcs/printf/ft_print_int.c \
	srcs/printf/ft_print_max.c \
	srcs/printf/ft_print_min.c \
	srcs/printf/ft_print_ptr.c \
	srcs/printf/ft_print_unsigned.c \
	srcs/printf/ft_putchar_int.c \
	srcs/printf/ft_putstr_int.c

OBJ := $(SRC:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                  RULES                                       #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo
	@echo "$(GREEN)$(BOLD)✔ libft.a compilée avec succès !$(RESET)"
	@echo

$(OBJ_DIR)/%.o: %.c
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@echo
	@echo "$(BLUE)🧹 Dossier '$(OBJ_DIR)' nettoyé.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)🗑️  Archive '$(NAME)' supprimée.$(RESET)"
	@echo

re: fclean all

.PHONY: all clean fclean re

