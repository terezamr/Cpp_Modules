NAME = diamond

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		 $(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all