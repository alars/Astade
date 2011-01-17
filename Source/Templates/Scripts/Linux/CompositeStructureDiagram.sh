#!/bin/bash -e

if [ -x /usr/bin/eog ]; then
	VIEWER="eog -n"
else
	VIEWER=display
fi

IMGDIR=$(mktemp -d)
IMGTYPE=png

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

CSDgenerator $* |dot -T${IMGTYPE} -o ${CHART}
${VIEWER} ${CHART}
