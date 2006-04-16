#!/bin/sh

ASTADEBINDIR=~/bin/
VIEWER="open" 
IMGDIR=/tmp
IMGTYPE=gif

: "$@"
NAME=$_
BASE=${NAME%/*}
CHART=${IMGDIR}/${BASE##*/}.${IMGTYPE}

${ASTADEBINDIR}/OMDgenerator $* |dot -T${IMGTYPE} -o ${CHART}

${VIEWER} ${CHART}
sleep 20
rm -f ${CHART}
