NAME = horde

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all