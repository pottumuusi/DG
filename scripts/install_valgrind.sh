#!/bin/sh

wget https://sourceware.org/pub/valgrind/valgrind-3.15.0.tar.bz2
tar -xvf valgrind-3.15.0.tar.bz2
cd valgrind-3.15.0.tar.bz2 && ./configure && make && sudo make install
