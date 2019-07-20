#!/bin/bash

set -ex

if [ ! -d libs ] ; then
	mkdir libs
fi

cd libs

ncurses_version="ncurses-6.1"

wget https://invisible-mirror.net/archives/ncurses/${ncurses_version}.tar.gz
tar -xvf ${ncurses_version}.tar.gz
cd ${ncurses_version}
./configure --prefix=/usr/local
make
sudo make install
