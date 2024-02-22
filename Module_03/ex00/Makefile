NAME = clap

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp ClapTrap.cpp

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		 $(CC) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all