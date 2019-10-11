# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/29 13:27:24 by ftrujill          #+#    #+#              #
#    Updated: 2019/07/14 19:52:39 by ftrujill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ftrujill.filler

CC = gcc
CC_FLAGS = -g -Wall -Werror -Wextra

OBJ_DIR = objects

SRC_PATH = ./sources/
OBJ_PATH = ./$(OBJ_DIR)/
INC_PATH = ./includes/
LFT_PATH = ./libft/

OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = filler.h
SRC_NAME = aux.c minimization.c filler.c
LIB_NAME = libft.a

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix $(INC_PATH),$(INC_NAME))
LIB = $(addprefix $(LFT_PATH),$(LIB_NAME))

all: $(NAME)

.PHONY : all re clean fclean

$(NAME): $(OBJ_PATH) $(OBJ) $(LIB)
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) $(OBJ) -L $(LFT_PATH) -lft -o $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_DIR)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CC_FLAGS) -I $(INC_PATH) -o $@ -c $< 

$(LIB):
	@make -C $(LFT_PATH)

clean:
	@rm -rf $(OBJ)
	@mkdir -p $(OBJ_DIR)
	@rmdir $(OBJ_DIR)
	@make -C $(LFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LFT_PATH) fclean

re: fclean all
