CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP

NAME :=  Unnecessary_violence
SRC := main.cpp Weapon.cpp HumanA.cpp HumanB.cpp
OBJ := $(SRC:.cpp=.o)

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