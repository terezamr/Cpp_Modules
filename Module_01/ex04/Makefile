NAME = replace

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp Replace.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		 $(CC) $(FLAGS) -o $(NAME) $(OBJS)
clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all