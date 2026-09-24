NAME = bureaucrat

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

RM = rm -f

SRCS = main.cpp Bureaucrat.cpp

HEADERS = Bureaucrat.hpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re
