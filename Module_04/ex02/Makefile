NAME = Aanimal

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp Aanimal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all