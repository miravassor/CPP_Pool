# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avassor <avassor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 16:45:05 by avassor           #+#    #+#              #
#    Updated: 2023/12/12 15:42:18 by avassor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

SRCS		=	main.cpp \
				PmergeMe.cpp \
				dequeMergeMe.cpp \
				vectorMergeMe.cpp

HEADERS		=	PmergeMe.hpp \
				dequeMergeMe.hpp \
				vectorMergeMe.hpp

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
