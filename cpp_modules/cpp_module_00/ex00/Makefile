# tool macros
CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
#DGBFLAGS := -g

# compile macros
NAME := megaphone

# src files & obj files
SRC := megaphone.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(DGBFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
