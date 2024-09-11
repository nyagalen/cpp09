# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 18:59:31 by svydrina          #+#    #+#              #
#    Updated: 2024/08/19 19:31:07 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = btc

SRC = BitcoinExchange.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

HEADER = BitcoinExchange.hpp

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all