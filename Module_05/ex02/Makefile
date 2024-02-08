NAME = aform

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 

RM = rm -rf

SRC = main.cpp Bureaucrat.cpp PresidentialPardonForm.cpp

OBJS = $(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)
	
fclean:	clean
		$(RM) $(NAME)

re:	fclean all