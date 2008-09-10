#!/bin/bash --

VERSION=`awk -F '"' '{print $2}' Model/components_WGNBOFKH/component_KSEQOEET/manual/AstadeVersion.h`

find ${PWD}/{Model,Source/{Icons,icons_png,Templates},build_{all,mac}*,*.txt} \
	\( -name .svn -o -name html \) -prune -o \
	-type l -print -o \
	-type f \! -name ".*" \! -name "*.[ao]" -a \
	\( -name "*.sh" -o \! -perm +111 \) -print \
	|pax -ws,^${PWD},astade-${VERSION}, |gzip >astade-${VERSION}.tar.gz
