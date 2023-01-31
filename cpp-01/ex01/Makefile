NAME = zombiehorde

SRCS = main.cpp Zombie.cpp Zombiehorde.cpp

OBJS = $(SRCS:.cpp=.o)

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

CXX = g++

${NAME}: $(OBJS)
		$(CXX) $(CXXFLAGS) -o zombie $(OBJS)

all : ${NAME}
bonus :
clean :
		rm -f ${OBJS}
fclean : clean
		rm -f ${NAME}
re : fclean all