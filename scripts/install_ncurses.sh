#!/bin/bash

set -ex

if [ ! -d libs ] ; then
	mkdir libs
fi

cd libs

ncurses_version="ncurses-6.1"

wget ftp://ftp.invisible-island.net/ncurses/${ncurses_version}.tar.gz
tar -xvf ${ncurses_version}.tar.gz
cd ${ncurses_version}
./configure --prefix=/usr/local
make
sudo make install
