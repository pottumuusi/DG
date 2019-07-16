CXX := $(shell which clang++ clang++-8 2> /dev/null | tail -1 | xargs basename)
TIDY := $(shell which clang-tidy clang-tidy-8 2> /dev/null | tail -1 | xargs basename)
VALGRIND := valgrind

SRC_DIR := src
TEST_DIR := test
OUT_DIR := out
OUT_TEST_DIR := $(OUT_DIR)/test
INCLUDE_TOP_DIR := include

OUT_BIN_NAME := DG
OUT_BIN := $(OUT_DIR)/$(OUT_BIN_NAME)
OUT_TEST_BIN_NAME := DG_test
OUT_TEST_BIN := $(OUT_TEST_DIR)/$(OUT_TEST_BIN_NAME)

SRC_FILES := $(shell find $(SRC_DIR)/ -name *.cxx)
TEST_SRC_FILES := $(shell find $(TEST_DIR)/ -name *.cxx)
TEST_DEPS := $(filter-out $(SRC_DIR)/main.cxx,$(SRC_FILES)) $(TEST_SRC_FILES)

# Define OBJ_FILES in case wanting to use in future
OBJ_FILES := $(SRC_FILES:.cxx=.o)
VALGRIND_OUTPUT_FAILURE_TAG := LEAK

INCS := -I$(INCLUDE_TOP_DIR)
TEST_INCS := -I/opt/gtest/include/

# NOTE include flags __need__ to be on the left end of arguments.
CXX_FLAGS := $(INCS)
CXX_TEST_FLAGS := -L/opt/gtest/lib -lgtest -lpthread $(CXX_FLAGS) $(TEST_INCS)

TIDY_OPTS := \
    -checks=*,-fuchsia-default-arguments \
    -warnings-as-errors=*
TIDY_COMPILATION_OPTS := -- $(INCS) $(TEST_INCS)
TIDY_FLAGS := $(TIDY_OPTS) $(TIDY_COMPILATION_OPTS)

# .PHONY:

# TODO automatic dep file creation (to track included files) by using cpp

game: $(OUT_BIN)
	echo all OK

test: $(OUT_TEST_BIN)
	echo test OK

analyze: $(SRC_FILES) $(TEST_SRC_FILES) $(OUT_BIN)
	$(TIDY) $(SRC_FILES) $(TEST_SRC_FILES) $(TIDY_FLAGS)
	echo Running valgrind...
	$(shell if [ -n "$$($(VALGRIND) $(OUT_BIN) 2>&1 1>/dev/null | grep $(VALGRIND_OUTPUT_FAILURE_TAG))" ] ; then echo "Fail: leak detected by valgrind" ; fi)
	echo analyze OK

# Having linker flags before source files caused build to fail during linking.
$(OUT_BIN): $(SRC_FILES)
	$(shell if [ ! -d $(OUT_DIR) ] ; then mkdir $(OUT_DIR) ; fi)
	$(CXX) -o $@ $^ $(CXX_FLAGS)

# Having linker flags before source files caused build to fail during linking.
$(OUT_TEST_BIN): $(TEST_DEPS)
	echo TEST_DEPS IS: $(TEST_DEPS)
	$(shell if [ ! -d $(OUT_TEST_DIR) ] ; then mkdir $(OUT_TEST_DIR) ; fi)
	$(CXX) -o $@ $^ $(CXX_TEST_FLAGS) $(INCS)
	echo OK

run: game
	$(OUT_BIN)

run_tests: test
	$(OUT_TEST_BIN)
	echo run_tests OK
