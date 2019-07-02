CXX := clang++-8
TIDY := clang-tidy-8
TIDY_OPTS := -checks=* -warnings-as-errors=*
TIDY_COMPILATION_OPTS := --
TIDY_FLAGS := $(TIDY_OPTS) $(TIDY_COMPILATION_OPTS)

SRC_DIR := src
OUT_DIR := out

OUT_BIN_NAME := DG
OUT_BIN := $(OUT_DIR)/$(OUT_BIN_NAME)

SRC_FILES := $(wildcard */*.cxx)

# .PHONY:

# TODO automatic dep file creation (to track included files) by using cpp

# TODO add further dependencies, object files instead of sources
all: $(SRC_FILES)
	$(shell if [ ! -d $(OUT_DIR) ] ; then mkdir $(OUT_DIR) ; fi)
	$(CXX) -o $(OUT_BIN) $(SRC_FILES)

analyze: $(SRC_FILES)
	$(TIDY) $(SRC_FILES) $(TIDY_FLAGS)
	echo OK

test: all
	$(shell test "$$($(OUT_BIN))" = "Hello world!" ; if [ 0 != $$(echo $$?) ] ; then echo "Shell test failure" ; fi)
	echo OK
