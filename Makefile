# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhonchar <mhonchar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/05 13:02:55 by htkachuk          #+#    #+#              #
#    Updated: 2019/10/06 18:47:55 by mhonchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program.
NAME     := ft_retro

# Sources and objects.
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = src/

SRC_FILES =		main.cpp \
				Player.cpp \
				Game.cpp \
				Symbol.cpp \
				Bullet.cpp \
				Enemy.cpp

# HEADERS = 		$(INC_DIR)ClassPlayer.hpp

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_FILES:.cpp=.o))
INC = 	-I $(INC_DIR)

# Define all the compiling flags.
CXX      := clang++
CXXFLAGS := 
LIB = -lncurses

C_RED = \033[31m
C_GREEN = \033[32m
C_MAGENTA = \033[35m
C_NONE = \033[0m

# Compile and create everything.
all: $(NAME)

$(NAME): $(HEADERS) $(OBJ_DIR) $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR):
	@mkdir obj
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(HEADERS)
	@$(CXX) $(CXXFLAGS) -c $(INC) $< -o $@
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_GREEN)[done]$(C_NONE)\n" $@

clean:
	@rm -rf $(OBJ_DIR)*
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

fclean: clean
	@rm -rf $(NAME)
	@printf "$(C_MAGENTA)$(NAME):$(C_NONE) %-25s$(C_RED)[done]$(C_NONE)\n" $@

re: fclean all
