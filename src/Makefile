PROJECT = s21_containers

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror
TESTFLAGS = -lgtest -lgtest_main -pthread

DIR_TESTS = tests/
DIR_BUILD_TESTS = build_tests/

TEST_SRC = $(DIR_TESTS)*.cc
TEST_EXECUTABLE = $(DIR_BUILD_TESTS)$(PROJECT)_test

all: test

test: dir
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(TESTFLAGS) -o $(TEST_EXECUTABLE)
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
	rm -rf $(DIR_BUILD) $(DIR_OBJ) $(DIR_BUILD_TESTS)

