#!/bin/bash -e

if [ -x /usr/bin/eog ]; then
	VIEWER=eog
else
	VIEWER=display
fi

IMGDIR=/tmp
IMGTYPE=png

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

OMDgenerator $* |dot -T${IMGTYPE} -o ${CHART}
${VIEWER} ${CHART}
rm -f ${CHART}
