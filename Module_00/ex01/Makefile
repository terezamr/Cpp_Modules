NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM = rm -f

SRC = main.cpp PhoneBook.cpp Contact.cpp aux.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME) $(OBJS)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all