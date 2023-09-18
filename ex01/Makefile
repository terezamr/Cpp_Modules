NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = PhoneBook.cpp Contact.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME) $(OBJS)

$(NAME):	$(OBJS)
			$(CC) $(SRC) $(CFLAGS) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all