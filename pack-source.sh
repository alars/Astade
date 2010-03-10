#!/bin/bash --

VERSION=`awk -F '"' '{print $2}' Model/components_WGNBOFKH/component_KSEQOEET/manual/AstadeVersion.h`

find -L ${PWD}/{Model,Source/{AstadeView,Icons,icons_png,Templates},build_{all,mac}*,*.txt} \
	\( -name .svn -o -name html \) -prune -o \
	-type f \! -name ".*" \! -name "*.[ao]" -a \
	\( -name "*.py" -o -name "*.sh" -o \! -perm +111 \) -print \
	|pax -ws,^${PWD},astade-${VERSION}, |gzip >Source/astade-${VERSION}.tar.gz

zip -qrj Source/Templates/ACF.zip Model/Components_AstadeFramework/Component_ACF/ -i '*.c' -i '*.h'
