#!/bin/bash --

MAINDIST="trusty"

if [[ $DIST == $MAINDIST ]]; then
        SUFFIX=""
else
        SUFFIX="~${DIST}${DIST_PATCHLEVEL}"
fi
