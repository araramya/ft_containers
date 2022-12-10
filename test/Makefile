CXX=clang++
CXXFLAGS=-Wall -Wextra -Werror -O0
OBJECTS=Test.o main.o \
	main_vector.o \
	main_stack.o \
	main_map.o 
NAME=test_all

.PHONY: run all clean fclean re

all: clean run

run: $(NAME)
	./test_all

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
