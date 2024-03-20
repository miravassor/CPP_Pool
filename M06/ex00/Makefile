# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/16 15:14:59 by avassor           #+#    #+#              #
#    Updated: 2023/11/21 16:24:19 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert

SRCS		=	main.cpp	\
				ScalarConverter.cpp \
				Converters.cpp

HEADERS		=	ScalarConverter.hpp

CC = c++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98

OBJPATH		=	.obj
OBJ			=	$(addprefix $(OBJPATH)/, $(SRCS:%.cpp=%.o))

$(OBJPATH)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJPATH)
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ) $(HEADERS)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJPATH) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
