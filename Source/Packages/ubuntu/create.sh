#!/bin/bash

DIRNAME=$(dirname $0)
MAINDIST="precise"
DIST="precise"
CHANGELOG="debian/changelog"
CHANGELOG_NAME="Astade Developers"
CHANGELOG_EMAIL="dev@astade.tigris.org"

source version

source ${DIRNAME}/getopts.sh

if [[ $DIST == $MAINDIST ]]; then
        SUFFIX=""
else
        SUFFIX="~${DIST}1"
fi

tar xzf astade_${VERSION}.tar.gz
ln -s astade_${VERSION}.tar.gz astade_${VERSION}.orig.tar.gz
cp -r Source/Packages/ubuntu/${DIST}/debian astade-${VERSION}/

pushd astade-${VERSION}

echo  > ${CHANGELOG} "astade (${VERSION}-0ubuntu1${SUFFIX}) ${DIST}; urgency=low"
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} "  * The full changelog can be found at git hub."
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} " -- ${CHANGELOG_NAME} <${CHANGELOG_EMAIL}>  $(date -R)"
echo >> ${CHANGELOG}

debuild -S

popd

exit 0

