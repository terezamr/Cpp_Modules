NAME = horde

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp Zombie.cpp zombieHorde.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME) $(OBJS)

$(NAME):	$(OBJS)
			$(CC) $(SRC) $(FLAGS) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all