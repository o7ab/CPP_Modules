NAME = Violence

SRCS = main.cpp Weapons.cpp HumanA.cpp HumanB.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -O3 -g3 -Wall -Werror -Wextra -Wno-shadow -std=c++98

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