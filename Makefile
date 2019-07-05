CXX := $(shell which clang++ clang++-8 2> /dev/null | tail -1 | xargs basename)
TIDY := $(shell which clang-tidy clang-tidy-8 2> /dev/null | tail -1 | xargs basename)
TIDY_OPTS := \
    -checks=*,-fuchsia-default-arguments \
    -warnings-as-errors=*
TIDY_COMPILATION_OPTS := --
TIDY_FLAGS := $(TIDY_OPTS) $(TIDY_COMPILATION_OPTS)

SRC_DIR := src
OUT_DIR := out

OUT_BIN_NAME := DG
OUT_BIN := $(OUT_DIR)/$(OUT_BIN_NAME)

SRC_FILES := $(wildcard */*.cxx)
# Define OBJ_FILES in case wanting to use in future
OBJ_FILES := $(SRC_FILES:.cxx=.o)

# .PHONY:

# TODO automatic dep file creation (to track included files) by using cpp

all: $(OUT_BIN)

$(OUT_BIN): $(SRC_FILES)
	$(shell if [ ! -d $(OUT_DIR) ] ; then mkdir $(OUT_DIR) ; fi)
	$(CXX) -o $@ $^

analyze: $(SRC_FILES)
	$(TIDY) $^ $(TIDY_FLAGS)
	echo OK

test: all
	$(shell test "$$($(OUT_BIN) | grep 'Player 1')" = "Name of actors[0] is: Player 1" ; if [ 0 != $$(echo $$?) ] ; then echo "Shell test failure" ; fi)
	echo OK

run: all
	$(OUT_BIN)
