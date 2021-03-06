#!/bin/bash -e

if [ -x /usr/bin/eog ]; then
	VIEWER="eog -n"
elif [ -x /usr/bin/okular ]; then
	VIEWER=okular
else
	VIEWER=display
fi

IMGDIR=$(mktemp -d)
IMGTYPE=png

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

OMDgenerator $* |dot -T${IMGTYPE} -o ${CHART}
${VIEWER} ${CHART}
