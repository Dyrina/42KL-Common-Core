CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -MMD -MP

VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

NAME :=  Sed_is_for_losers
SRC := main.cpp File.cpp
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

test: $(NAME)
	@echo "--- 1. Setting up test files ---"
	echo "Hello world! test test test" > test_in.txt
	echo "aaaaa" > test_loop.txt
	@echo "\n"

	@echo "--- 2. Standard Replacement Test ---"
	./$(NAME) test_in.txt "test" "exam"
	printf "Hello world! exam exam exam\n" | diff -u test_in.txt.replace - && echo "Standard test: OK"
	@echo "\n"

	@echo "--- 3. Expansion Test (a -> aa) ---"
	./$(NAME) test_loop.txt "a" "aa"
	printf "aaaaaaaaaa\n" | diff -u test_loop.txt.replace - && echo "Loop trap test: OK"
	@echo "\n"

	@echo "--- 4. Error Handling Checks ---"
	./$(NAME) 2>/dev/null && echo "FAIL: Should reject missing args" || echo "Arg check: OK"
	./$(NAME) non_existent.txt "a" "b" 2>/dev/null && echo "FAIL: Should reject missing file" || echo "Missing file check: OK"
	@echo "\n"

	@echo "--- 5. Cleanup ---"
	rm -f test_in.txt test_in.txt.replace test_loop.txt test_loop.txt.replace
	@echo "\n"
	@echo "All tests completed!"

mem_test: $(NAME)
	@echo "--- Setting up memory test files ---"
	@printf "Line 1: testing leaks\nLine 2: test test test\n" > mem_in.txt

	@echo "--- 1. Testing standard execution ---"
	@$(VALGRIND) ./$(NAME) mem_in.txt "test" "exam" > /dev/null

	@echo "--- 2. Testing error path: invalid arguments ---"
	@$(VALGRIND) ./$(NAME) > /dev/null 2>&1 || [ $$? -ne 42 ]

	@echo "--- 3. Testing error path: non-existent file ---"
	@$(VALGRIND) ./$(NAME) non_existent.txt "a" "b" > /dev/null 2>&1 || [ $$? -ne 42 ]

	@echo "--- 4. Cleanup ---"
	@rm -f mem_in.txt mem_in.txt.replace
	@echo "Valgrind: 0 leaks detected across all paths!"

clean:
	rm -f $(OBJ) $(OBJ:.o=.d)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test mem_test