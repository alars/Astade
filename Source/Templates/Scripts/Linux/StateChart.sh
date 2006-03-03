#!/bin/sh

VIEWER=display
IMGDIR=/tmp
IMGTYPE=gif

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

StateChartDrawer $* |dot -T${IMGTYPE} -o ${CHART}
${VIEWER} ${CHART}
rm -f ${CHART}
