#!/bin/bash -e

VIEWER=display
IMGDIR=/tmp
IMGTYPE=png

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

OMDgenerator $* |dot -T${IMGTYPE} -o ${CHART}
${VIEWER} ${CHART}
rm -f ${CHART}
