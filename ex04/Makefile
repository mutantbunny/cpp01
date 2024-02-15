CC = c++
CFLAGS = -Wall -Wextra -Werror -ggdb -std=c++98
RM = rm -f

NAME = ft_sed

SRCS = main.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

leaks: $(NAME)
	valgrind --leak-check=full ./$(NAME)

re: fclean all

test_args: $(NAME)
	@echo
	@echo "***********"
	@echo

	@echo "Test: Call program without arguments"
	@echo
	@echo "Expected: Show the following usage message:"
	@echo "Usage: ./$(NAME) filename s1 s2"
	@echo "Replace every occurrence of s1 with s2 in file filename and save result to file filename.replace"
	@echo
	@echo "Result:"
	-./$(NAME) || true
	@echo
	@echo "***********"
	@echo

	@echo "Test: Call program with one argument"
	@echo
	@echo "Expected: Show the following usage message:"
	@echo "Usage: ./$(NAME) filename s1 s2"
	@echo "Replace every occurrence of s1 with s2 in file filename and save result to file filename.replace"
	@echo
	@echo "Result:"
	-./$(NAME) filename || true
	@echo
	@echo "***********"
	@echo

	@echo "Test: Call program with two arguments"
	@echo
	@echo "Expected: Show the following usage message:"
	@echo "Usage: ./$(NAME) filename s1 s2"
	@echo "Replace every occurrence of s1 with s2 in file filename and save result to file filename.replace"
	@echo
	-./$(NAME) filename str1 || true
	@echo
	@echo "***********"
	@echo

test_invalid_files: $(NAME)
	@echo
	@echo "***********"
	@echo

	@echo "Test: Non-existing input file"
	@echo
	@echo "Expected: Show error message"
	@echo "Error: could not open file test_file for reading."
	@echo

	@echo "Result:"
	@$(RM) test_file
	-./$(NAME) test_file jumps hops || true
	@echo
	@echo "***********"
	@echo

	@echo "Test: Input file has no read permission"
	@echo
	@echo "Expected: Show error message"
	@echo "Error: could not open file test_file for reading."
	@echo

	@echo "The quick brown fox jumps over the lazy dog" > test_file
	@chmod 222 test_file
	-./$(NAME) test_file jumps hops || true
	@$(RM) test_file
	@echo
	@echo "***********"
	@echo

	@echo "Test: Output file has no write permission"
	@echo
	@echo "Expected: Show error message"
	@echo "Error: could not open file test_file.replace for writing."
	@echo

	@echo "The quick brown fox jumps over the lazy dog" > test_file
	@touch test_file.replace
	@chmod 444 test_file.replace
	-./$(NAME) test_file jumps hops || true
	@chmod 644 test_file.replace
	@$(RM) test_file
	@$(RM) test_file.replace

	@echo
	@echo "***********"
	@echo

test_valid_files: $(NAME)
	@echo
	@echo "***********"
	@echo

	@echo "Test: Empty input file"
	@echo
	@echo "Expected: Empty output file."
	@echo

	@touch test_file
	-./$(NAME) test_file jumps hops

	@echo "Result: Output file contents between - - - - - - lines:"
	@echo "- - - - - -"
	@cat test_file.replace
	@echo
	@echo "- - - - - -"
	@echo

	@$(RM) test_file
	@$(RM) test_file.replace
	@echo
	@echo "***********"
	@echo

	@echo "Test: Input file with a single newline character"
	@echo
	@echo "Expected: Output file with a single newline character."
	@echo

	@echo "" > test_file
	-./$(NAME) test_file jumps hops

	@echo "Result: Output file contents between - - - - - - lines:"
	@echo "- - - - - -"
	@cat test_file.replace
	@echo
	@echo "- - - - - -"
	@echo

	$(RM) test_file
	$(RM) test_file.replace
	@echo
	@echo "***********"
	@echo

	@echo "Test: Input file with a single line, no newline character"
	@echo
	@echo "Expected:"
	@echo "- - - - - -"
	@echo "The quick brown fox hops over the lazy dog"
	@echo "- - - - - -"
	@echo

	@echo -n "The quick brown fox jumps over the lazy dog" > test_file
	-./$(NAME) test_file jumps hops

	@echo "Result: Output file contents between - - - - - - lines:"
	@echo "- - - - - -"
	@cat test_file.replace
	@echo
	@echo "- - - - - -"
	@echo

	$(RM) test_file
	$(RM) test_file.replace

	@echo
	@echo "***********"
	@echo

	@echo "Test: Input file with a single line, with newline character"
	@echo
	@echo "Expected:"
	@echo "- - - - - -"
	@echo "The quick brown fox hops over the lazy dog"
	@echo
	@echo "- - - - - -"
	@echo

	echo "The quick brown fox jumps over the lazy dog" > test_file
	-./$(NAME) test_file jumps hops

	@echo "Result: Output file contents between - - - - - - lines:"
	@echo "- - - - - -"
	@cat test_file.replace
	@echo
	@echo "- - - - - -"
	@echo

	@$(RM) test_file
	@$(RM) test_file.replace

	@echo
	@echo "***********"
	@echo

	@echo "Test: Input file with multiple lines, no newline character at the end"
	@echo
	@echo "Expected:"
	@echo "- - - - - -"
	@echo "The quick brown fox hops over the lazy dog hops over the quick fox."
	@echo "hops and hops and hops!"
	@echo
	@echo "Blah blah Blah"
	@echo "More hops here"
	@echo "Only one jump and two pumps here."
	@echo "hehehehe"
	@echo "- - - - - -"
	@echo

	@echo "The quick brown fox jumps over the lazy dog jumps over the quick fox." > test_file
	@echo "jumps and jumps and jumps!" >> test_file
	@echo "" >> test_file
	@echo "Blah blah Blah" >> test_file
	@echo "More jumps here" >> test_file
	@echo "Only one jump and two pumps here." >> test_file
	@echo -n "hehehehe" >> test_file
	-./$(NAME) test_file jumps hops

	@echo "Result: Output file contents between - - - - - - lines:"
	@echo "- - - - - -"
	@cat test_file.replace
	@echo
	@echo "- - - - - -"
	@echo

	@$(RM) test_file
	@$(RM) test_file.replace

	@echo
	@echo "***********"
	@echo

	@echo "Test: Input file with multiple lines, with a newline character at the end"
	@echo
	@echo "Expected:"
	@echo "- - - - - -"
	@echo "The quick brown fox hops over the lazy dog hops over the quick fox."
	@echo "hops and hops and hops!"
	@echo
	@echo "Blah blah Blah"
	@echo "More hops here"
	@echo "Only one jump and two pumps here."
	@echo "hehehehe"
	@echo
	@echo "- - - - - -"
	@echo

	@echo "The quick brown fox jumps over the lazy dog jumps over the quick fox." > test_file
	@echo "jumps and jumps and jumps!" >> test_file
	@echo "" >> test_file
	@echo "Blah blah Blah" >> test_file
	@echo "More jumps here" >> test_file
	@echo "Only one jump and two pumps here." >> test_file
	@echo "hehehehe" >> test_file
	-./$(NAME) test_file jumps hops

	@echo "Result: Output file contents between - - - - - - lines:"
	@echo "- - - - - -"
	@cat test_file.replace
	@echo
	@echo "- - - - - -"
	@echo

	@$(RM) test_file
	@$(RM) test_file.replace

	@echo
	@echo "***********"
	@echo

.PHONY: all clean fclean leaks re
