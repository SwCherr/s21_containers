PROJECT = s21_containers.a

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror --coverage
TESTFLAGS = -lgtest -lgtest_main -pthread
LIB_NAME = $(DIR_BUILD)$(PROJECT)

DIR_TESTS = ./tests/
DIR_OBJ = ./obj/
DIR_BUILD = ./build/
DIR_BUILD_TESTS = ./build_tests/

SRC = $(wildcard *.cc)
OBJ = $(patsubst %.cc, $(DIR_OBJ)%.o, $(SRC))

TEST_SRC = $(wildcard $(DIR_TESTS)*.cc)
TEST_OBJ = $(patsubst $(DIR_TESTS)%.cc, $(DIR_OBJ)%.o, $(TEST_SRC))
TEST_EXECUTABLE = $(DIR_BUILD_TESTS)test_matrix

$(PROJECT): dir $(OBJ)
	ar rcs $(LIB_NAME) $(OBJ)

$(DIR_OBJ)%.o: %.cc | dir
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_OBJ)%.o: $(DIR_TESTS)%.cc | dir
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_EXECUTABLE): $(TEST_OBJ) $(LIB_NAME)
	$(CXX) $(CXXFLAGS) $(GTEST_LIB) $^ -o $@ $(TESTFLAGS)

test: $(TEST_EXECUTABLE)
	$(TEST_EXECUTABLE)

gcov_report:
	gcov $(SRC)
	# lcov --directory . --capture --output-file $(DIR_BUILD_TESTS)coverage.info --exclude "/usr/local/*"
	lcov --directory . --capture --output-file $(DIR_BUILD_TESTS)coverage.info --exclude "/usr/local/*" --ignore-errors mismatch
	genhtml $(DIR_BUILD_TESTS)coverage.info --output-directory $(DIR_BUILD_TESTS)index.html
	open ./build_tests/index.html/index.html

dir:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_BUILD)
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

all: $(PROJECT) test
