NAME = interface

SRCS = main.cpp Cure.cpp Ice.cpp MateriaSource.cpp Character.cpp AMateria.cpp ICharacter.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = c++

${NAME}: $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all : ${NAME}
bonus :
clean :
		rm -f ${OBJS}
fclean : clean
		rm -f ${NAME}
re : fclean all