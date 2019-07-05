CXX := $(shell which clang++ clang++-8 2> /dev/null | tail -1 | xargs basename)
TIDY := $(shell which clang-tidy clang-tidy-8 2> /dev/null | tail -1 | xargs basename)
VALGRIND := valgrind

SRC_DIR := src
OUT_DIR := out
INCLUDE_TOP_DIR := include

OUT_BIN_NAME := DG
OUT_BIN := $(OUT_DIR)/$(OUT_BIN_NAME)

SRC_FILES := $(wildcard */*.cxx)
# Define OBJ_FILES in case wanting to use in future
OBJ_FILES := $(SRC_FILES:.cxx=.o)
VALGRIND_OUTPUT_FAILURE_TAG := LEAK

CXX_FLAGS := -I$(INCLUDE_TOP_DIR)

TIDY_OPTS := \
    -checks=*,-fuchsia-default-arguments \
    -warnings-as-errors=*
TIDY_COMPILATION_OPTS := -- -I$(INCLUDE_TOP_DIR)
TIDY_FLAGS := $(TIDY_OPTS) $(TIDY_COMPILATION_OPTS)

# .PHONY:

# TODO automatic dep file creation (to track included files) by using cpp

all: $(OUT_BIN)

$(OUT_BIN): $(SRC_FILES)
	$(shell if [ ! -d $(OUT_DIR) ] ; then mkdir $(OUT_DIR) ; fi)
	$(CXX) -o $@ $(CXX_FLAGS) $^

# $(shell if [ -n "$$($(VALGRIND) $(OUT_BIN) 2>&1 1>/dev/null | grep $(VALGRIND_OUTPUT_FAILURE_TAG))" ] ; then echo "Fail: leak detected by valgrind" ; fi)
analyze: $(SRC_FILES) $(OUT_BIN)
	$(TIDY) $(SRC_FILES) $(TIDY_FLAGS)
	echo Running valgrind...
	$(VALGRIND) $(OUT_BIN)
	echo OK

test: all
	$(shell test "$$($(OUT_BIN) | grep 'Player 1')" = "Name of actors[0] is: Player 1" ; if [ 0 != $$(echo $$?) ] ; then echo "Fail: no expected print" ; fi)
	echo OK

run: all
	$(OUT_BIN)
