COMPILE = c++ -g -Wall -Wextra -Werror -std=c++98 -fPIE
NAME = serializer
SRCS = main.cpp Serializer.cpp
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
