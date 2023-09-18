NAME = megaphone

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -rf

SRC = megaphone.cpp

OBJS 	= $(SRC:.c=.o)

all:	$(NAME) $(OBJS)

$(NAME):	$(OBJS)
			$(CC) $(SRC) $(FLAGS) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		$(RM) $(NAME)

re:	clean all