NAME		= game
CC	 		= g++
CPPFLAGS	= -Wall -Wextra -Werror -g -std=c++98
SOURCE		= main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS		= $(SOURCE:.cpp=.o)
RM			= rm -rf

all: 		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

%.o: 		%.cpp
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all, clean, fclean, re
