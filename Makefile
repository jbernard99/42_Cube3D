# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbernard <jbernard@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 04:45:18 by jbernard          #+#    #+#              #
#    Updated: 2023/09/05 14:38:56 by jbernard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#gcc -o minishell -I./libraries/readline/include ./src/main.c -L./libraries/readline/lib -lreadline -lncurses

include settings.mk

# Compiler and compiler flags
CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = Cube3D

# Directories
SRC_DIR = src/

MAIN_DIR = $(SRC_DIR)/main

INC_DIR = includes/
OBJ_DIR = obj/
LIBFT_DIR = ./libraries/42_libft

# Files
MAIN_FILES = 	main.c
				

OBJ_FILES = $(MAIN_FILES:%.c=$(OBJ_DIR)%.o)

LIB_FILES = -L$(LIBFT_DIR) -lft -L/usr/local -lmlx

VPATH =	$(SRC_DIR) 		\
		$(MAIN_DIR)

# Build rule
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@ printf "$(GREEN) Almost done ......\r$(RESET)"
	@ $(MAKE) -C $(LIBFT_DIR)
	@ $(CC) $(CFLAGS) $(OBJ_FILES) $(LIB_FILES) -o $(NAME)
	@ printf "$(GREEN) - ✅✅✅ -> Compilation of $(PURPLE)$(NAME)$(GREEN) complete!                      						      $(RESET)\n"

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)
	@ printf "$(GREEN)- ⚡⚡⚡ -> Compiling $(PURPLE)$(notdir $@)$(GREEN) using $(PURPLE)$(notdir $<)$(GREEN)...                                                                             \r$(RESET)"
	@ $(CC) $(CFLAGS) -g -gdwarf-4 -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@ mkdir -p $(OBJ_DIR)

#Management Rules
clean:
	@ rm -rf $(OBJ_DIR)
	@ $(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@ rm -f $(NAME)
	@ $(MAKE) -C $(LIBFT_DIR) fclean

re: clean all

.PHONY:		all clean fclean re obj
