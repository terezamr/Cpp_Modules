NAME = PmergeMe

CC = c++
CFLAGS = -Wall -Wextra -Werror  -std=c++98

RM = rm -rf

INC = inc/

SRC = $(wildcard *cpp)

OBJS = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		 $(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all
