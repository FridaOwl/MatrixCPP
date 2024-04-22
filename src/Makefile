.PHONY: all clean test
CXX = g++
CXXFLAGS_MAC = -std=c++17 -g -Wall -Werror -Wextra -lstdc++
CXXFLAGS_LINUX = -std=c++17 -g -Wall -Werror -Wextra -lstdc++ -ftest-coverage

LIB_SRCS = matrix_oop.cc operations_matrix_oop.cc operators_matrix_oop.cc
LIB_OBJS = $(LIB_SRCS:.cc=.o)
LIB_NAME = matrix_oop.a

TEST_SRCS = tests/tests.cc
TEST_OBJS = $(TEST_SRCS:.cc=.o)
TEST_EXEC = unit_test

OPEN_CMD_MAC = open
OPEN_CMD_LINUX = xdg-open

ifeq ($(shell uname), Darwin)
	CXXFLAGS = $(CXXFLAGS_MAC)
	OPEN_CMD = $(OPEN_CMD_MAC)
else
	CXXFLAGS = $(CXXFLAGS_LINUX)
	OPEN_CMD = $(OPEN_CMD_LINUX)
endif

all: $(LIB_NAME) $(TEST_EXEC)

matrix_oop.a:
	@$(CXX) $(CXXFLAGS) -c $(LIB_SRCS)
	@ar rcs matrix_oop.a $(LIB_OBJS)

test: matrix_oop.a
	@$(CXX) $(CXXFLAGS) $(TEST_SRCS) $< -o $(TEST_EXEC) -lgtest -lgtest_main -pthread --coverage
	@./$(TEST_EXEC)

gcov_report:
	@$(CXX) $(CXXFLAGS) --coverage $(LIB_SRCS) $(TEST_SRCS) -o $(TEST_EXEC) -lgtest -lgtest_main -pthread
	@./$(TEST_EXEC)
	@lcov -t "stest" -o test.info --no-external -c -d .
	@genhtml -o report test.info
	@$(OPEN_CMD) ./report/index.html

valgrind_check: $(TEST_EXEC)
	CK_FORK=no valgrind --tool=memcheck ./$(TEST_EXEC)

leaks:
	CK_FORK=no leaks -atExit -- ./$(TEST_EXEC)

style:
	clang-format -style=Google -n *.cc *.h

clean:
	rm -f $(LIB_NAME) $(LIB_OBJS) $(TEST_EXEC) $(TEST_OBJS)
	rm -rf *.dSYM
	rm -rf unit_test
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf test.info
	rm -rf report