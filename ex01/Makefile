NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRC = PhoneBook.cpp

all:	$(NAME)

$(NAME):	$(SRC)
			$(CC) $(SRC) $(CFLAGS) -o $(NAME)

clean:
		$(RM) $(NAME)

re:	clean all