CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g -MMD -MP

NAME := phonebook
SRC := main.cpp PhoneBook.cpp Contact.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(OBJ:.o=.d)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
