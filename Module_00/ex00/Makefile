NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all