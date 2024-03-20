# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:47:58 by avassor           #+#    #+#              #
#    Updated: 2023/09/20 10:32:38 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon
SRCS =	main.cpp	\
		HumanA.cpp	\
		HumanB.cpp	\
		Weapon.cpp
HEADER = HumanA.hpp	\
		HumanB.hpp	\
		Weapon.hpp

CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJPATH 	=	.obj
OBJ			=	$(addprefix $(OBJPATH)/, $(SRCS:%.cpp=%.o))

$(OBJPATH)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJPATH)
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJPATH) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
