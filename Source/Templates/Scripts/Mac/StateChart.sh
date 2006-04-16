#!/bin/sh
ASTADEBINDIR=~/bin/
VIEWER=open
IMGDIR=/tmp
IMGTYPE=gif

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

${ASTADEBINDIR}/StateChartDrawer $* |dot -T${IMGTYPE} -o ${CHART}
${VIEWER} ${CHART}
sleep 10
rm -f ${CHART}
