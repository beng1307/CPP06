# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgretic <bgretic@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/23 14:25:39 by bgretic           #+#    #+#              #
#    Updated: 2026/04/23 14:25:40 by bgretic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = c++ -g -Wall -Wextra -Werror -std=c++98 -fPIE
NAME = identify
SRCS = main.cpp Base.cpp
OBJS_FOLDER = obj
OBJS = $(SRCS:%.cpp=$(OBJS_FOLDER)/%.o)

$(NAME): $(OBJS)
	$(COMPILE) $(OBJS) -o $(NAME)

$(OBJS_FOLDER)/%.o: %.cpp
	@mkdir -p $(OBJS_FOLDER)
	$(COMPILE) -c $< -o $@

all: $(NAME)

clean:
	@rm -rf $(OBJS_FOLDER)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
