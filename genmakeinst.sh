#!/bin/bash -e

VERSION=$(git describe 2> /dev/null | sed "s/^release//" | sed "s/^v//" | sed "s/-\([0-9]*\)-\(g[0-9a-f]*\)/.\1~\2/")

./build_all.sh clean
./regenerate_all.sh
./build_all.sh
./do-unit-tests.sh
./build_deb.sh
for deb in build_*_deb.sh
do
	./$deb
done
sudo dpkg -i Source/Packages/deb/{astade{,draw,tools},trace2uml}-${VERSION}-*.deb
