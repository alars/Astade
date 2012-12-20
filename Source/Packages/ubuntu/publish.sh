#!/bin/bash

PPA_DAILY="astade/daily"
PPA_RELEASE="astade/release"
DAILYEXP='^([0-9]+\.){3}[0-9]+$'

source version

if [[ $VERSION =~ $DAILYEXP ]]; then
    PPA=${PPA_DAILY}
else
    PPA=${PPA_RELEASE}
fi

dput ppa:${PPA} astade_${VERSION}-0ubuntu1_source.changes

