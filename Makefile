CXX := clang++-8

SRC_DIR := src
OUT_DIR := out
BIN_NAME := DG

.PHONY: all test

all:
	$(shell if [ ! -d $(OUT_DIR) ] ; then mkdir $(OUT_DIR) ; fi)
	$(CXX) -o $(OUT_DIR)/$(BIN_NAME) $(SRC_DIR)/main.cpp

test:
	$(shell test "$$($(OUT_DIR)/$(BIN_NAME))" = "Hello world!" ; if [ 0 != $$(echo $$?) ] ; then echo "Shell test failure" ; fi)
	echo OK
