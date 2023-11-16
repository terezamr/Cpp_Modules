NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM = rm -rf

SRC = megaphone.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all