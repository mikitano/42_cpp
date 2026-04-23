# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkitano <mkitano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 19:21:59 by mkitano           #+#    #+#              #
#    Updated: 2026/04/23 19:21:59 by mkitano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

CC = c++
FLAGS =  -Wall -Wextra -Werror -std=c++98

SRC_DIR =	src
OBJ_DIR =	obj
INC_DIR =	include

SRC_FILES = main.cpp \
			newZombie.cpp \
			randomChump.cpp \
			Zombie.cpp

FILES_O = $(SRC_FILES:.cpp=.o)

OBJS = $(addprefix $(OBJ_DIR)/, $(FILES_O))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

INCLUDES = -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "[\033[0;32mOK\033[0m] $(NAME) COMPILED!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@
	@echo "[\033[0;32mOK\033[0m] COMPILED $<"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "[\033[0;32mOK\033[0m] FILES CLEAR!"

fclean: clean
	@rm -f $(NAME)
	@echo "[\033[0;32mOK\033[0m] ALL CLEAR!"

re: fclean all

.PHONY: all clean fclean re