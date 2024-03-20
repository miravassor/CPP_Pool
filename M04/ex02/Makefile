# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 15:24:50 by avassor           #+#    #+#              #
#    Updated: 2023/09/28 11:19:40 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Abstract

SRCS		=	main.cpp		\
				Dog.cpp			\
				Cat.cpp			\
				Animal.cpp		\
				Brain.cpp		\
				WrongAnimal.cpp \
				WrongCat.cpp

HEADER		=	Dog.hpp			\
				Cat.hpp			\
				Animal.hpp		\
				Brain.hpp		\
				WrongAnimal.hpp \
				WrongCat.hpp

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
