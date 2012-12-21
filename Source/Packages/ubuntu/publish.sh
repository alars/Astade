#!/bin/bash

DIRNAME=$(dirname $0)
MAINDIST="precise"
DIST="precise"
PPA_DAILY="astade/daily"
PPA_RELEASE="astade/release"
DAILYEXP='^([0-9]+\.){3}[0-9]+$'

source version

source ${DIRNAME}/getopts.sh

if [[ $DIST == $MAINDIST ]]; then
        SUFFIX=""
else
        SUFFIX="~${DIST}1"
fi

if [[ $VERSION =~ $DAILYEXP ]]; then
    PPA=${PPA_DAILY}
else
    PPA=${PPA_RELEASE}
fi

dput ppa:${PPA} astade_${VERSION}-0ubuntu1${SUFFIX}_source.changes

