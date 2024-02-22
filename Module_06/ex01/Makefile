NAME = serializer

CC = c++
CFLAGS = -g -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = main.cpp Serializer.cpp

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