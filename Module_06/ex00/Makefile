NAME = converter

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp ScalarConverter.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all