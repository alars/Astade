#!/bin/bash --

MAINDIST="precise"

if [[ $DIST == $MAINDIST ]]; then
        SUFFIX=""
else
        SUFFIX="~${DIST}${DIST_PATCHLEVEL}"
fi
