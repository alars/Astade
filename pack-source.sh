#!/bin/bash --

VERSION=$(git describe 2> /dev/null | sed "s/^release//" | sed "s/^v//" | sed "s/-\([0-9]*\)-\(g[0-9a-f]*\)/.\1~\2/")

echo "#define AstadeVersion \"${VERSION}\"" > Model/Components_Astade_components/Component_Astade/manual/AstadeVersion.h

find -L ${PWD}/{Model,Source/{AstadeView,Icons,icons_png,Templates,freedesktop},build_{all,mac}*,*.txt} \
	\( -name .svn -o -name html \) -prune -o \
	-type f \! -name ".*" \! -name "*.[ao]" -a \
	\( -name "*.py" -o -name "*.sh" -o \! -perm +111 \) -print \
	|pax -ws,^${PWD},astade-${VERSION}, | gzip > astade_${VERSION}.tar.gz

zip -qrj Source/Templates/ACF.zip Model/Components_AstadeFramework/Component_ACF/ -i '*.c' -i '*.h'
