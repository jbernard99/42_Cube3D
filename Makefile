# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smayrand <smayrand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/16 04:45:18 by jbernard          #+#    #+#              #
#    Updated: 2023/09/18 17:16:32 by smayrand         ###   ########.fr        #
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
GAME_DIR = $(SRC_DIR)/game
PLYR_DIR = $(SRC_DIR)/player

INC_DIR = includes/
OBJ_DIR = obj/
LIBFT_DIR = ./libraries/42_libft

# Files
MAIN_FILES = 	main.c
GAME_FILES =	game.c exit.c read_map.c
PLYR_FILES = 	player.c key_hook.c
				

OBJ_FILES = $(MAIN_FILES:%.c=$(OBJ_DIR)%.o) \
			$(GAME_FILES:%.c=$(OBJ_DIR)%.o) \
			$(PLYR_FILES:%.c=$(OBJ_DIR)%.o)

LIB_FILES = -L$(LIBFT_DIR) -lft -Llibraries/42_libft -lmlx -Llibraries/mlx -framework OpenGL -framework AppKit

VPATH =	$(SRC_DIR) 		\
		$(MAIN_DIR)		\
		$(GAME_DIR)		\
		$(PLYR_DIR)

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

obj:
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
