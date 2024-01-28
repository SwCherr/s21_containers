PROJECT = s21_containers

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
TESTFLAGS = -lgtest -lgtest_main -pthread
# GCOV_FLAG = --coverage #-fprofile-arcs -ftest-coverage

DIR_TESTS = tests/
DIR_BUILD_TESTS = build_tests/

TEST_SRC = $(DIR_TESTS)*.cc
TEST_EXECUTABLE = $(DIR_BUILD_TESTS)$(PROJECT)_test

all: clean test

test: dir
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(TESTFLAGS) $(GCOV_FLAG) -o $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

dir:
	@mkdir -p $(DIR_BUILD_TESTS)

style_check:
	cp ../materials/linters/.clang-format ../src/
	@find . -type f -name '*.cc' -or -name '*.h' | xargs -I {} sh -c 'echo "Checking {}" && clang-format -n {}'
	@find $(DIR_TESTS) -type f -name '*.cc' -or -name '*.h' | xargs -I {} sh -c 'echo "Checking {}" && clang-format -n {}'
	rm -rf .clang-format

style_repair: clean
	cp ../materials/linters/.clang-format ../src/
	@find . -type f -name '*.cc' -or -name '*.h' | xargs -I {} sh -c 'echo "Formatting {}" && clang-format -i {}'
	@find $(DIR_TESTS) -type f -name '*.cc' -or -name '*.h' | xargs -I {} sh -c 'echo "Formatting {}" && clang-format -i {}'
	rm -rf .clang-format

clean:
	rm -rf $(DIR_BUILD) $(DIR_OBJ) $(DIR_BUILD_TESTS) build/
	@rm -rf *.gcda *.gcno *.info *.dSYM 

gcov_report: $(STAT_LIB) test
	@./$(TEST_EXECUTABLE)
	@lcov -o test.info --no-external -c -d . $(LCOV_FLAG)
	@genhtml -o report test.info $(LCOV_FLAG)
	@$(OPEN_CMD) report/index.html
	@rm -rf *.gcda *.gcno *.info *.dSYM 



# OS = $(shell uname)
# CC = g++ -Wall -Werror -Wextra -std=c++17 -g
# # GCOV_FLAG = --coverage #-fprofile-arcs -ftest-coverage

# ifeq ($(OS), Linux)
# 	OPEN_CMD = xdg-open
# 	GTEST_FLAGS = -lgtest -lgtest_main -pthread
# endif
# ifeq ($(OS), Darwin)
# 	OPEN_CMD = open
# 	LCOV_FLAG = --ignore-errors inconsistent
# 	GTEST_FLAGS = -lgtest -lgmock -pthread -lgtest_main
# endif

# DIR_PROJECT = ./project/
# DIR_TESTS = ./tests/
# STAT_LIB = s21_containers.a
# EXECUTABLE = test_conteiners
# FILES_SRC = $(wildcard $(DIR_PROJECT)*.cc)
# FILES_TESTS = $(wildcard $(DIR_TESTS)*.cc)

# $(STAT_LIB): clean
# 	@$(CC) $(GCOV_FLAG) $(FILES_SRC) -c
# 	@ar rc $(STAT_LIB) *.o
# 	@ranlib $(STAT_LIB)
# 	@-rm -rf *.o

# test: $(STAT_LIB)
# 	@$(CC) $(FILES_TESTS) $(STAT_LIB) -o $(EXECUTABLE) $(GTEST_FLAGS) $(GCOV_FLAG) 
# 	@./$(EXECUTABLE)

# gcov_report: $(STAT_LIB) test
# 	@./$(EXECUTABLE)
# 	@lcov -o test.info --no-external -c -d . $(LCOV_FLAG)
# 	@genhtml -o report test.info $(LCOV_FLAG)
# 	@$(OPEN_CMD) report/index.html
# 	@rm -rf *.gcda *.gcno *.info *.dSYM 

# clean:
# 	@rm -rf *.a *.o
# 	@rm -rf $(EXECUTABLE)
# 	@rm -rf *.gcda *.gcno *.info *.dSYM 
# 	@rm -rf report

# leaks: test
# 	@leaks -atExit -- ./$(EXECUTABLE) | grep LEAK:

# valgrind: test
# 	@valgrind --tool=memcheck --leak-check=yes ./$(EXECUTABLE)
# #	@CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(EXECUTABLE)

# style_cp:
# 	cp ../materials/linters/.clang-format ../src  

# style_preparation: clean style_cp
# 	clang-format -style=Google -i $(DIR_PROJECT)*.cpp $(DIR_PROJECT)*.h
# 	clang-format -style=Google -i $(DIR_TESTS)*.cpp $(DIR_TESTS)*.h
# 	@rm -rf .clang-format

# style_check: clean style_cp
# 	clang-format -style=Google -n $(DIR_PROJECT)*.cpp $(DIR_PROJECT)*.h
# 	clang-format -style=Google -n $(DIR_TESTS)*.cpp $(DIR_TESTS)*.h
# 	@rm -rf .clang-format

# # Цель по умолчанию
# all:

# .PHONY: all clean test