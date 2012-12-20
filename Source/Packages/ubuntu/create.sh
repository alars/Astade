#!/bin/bash

MAINDIST="precise"
DIST="precise"
CHANGELOG="debian/changelog"

if [[ $DIST == $MAINDIST ]]; then
        SUFFIX=""
else
        SUFFIX="-${DIST}1"
fi

source version

tar xzf astade_${VERSION}.tar.gz
ln -s astade_${VERSION}.tar.gz astade_${VERSION}.orig.tar.gz
cp -r Source/Packages/ubuntu/${DIST}/debian astade-${VERSION}/

pushd astade-${VERSION}

echo  > ${CHANGELOG} "astade (${VERSION}-0ubuntu1${SUFFIX}) ${DIST}; urgency=low"
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} "  * The full changelog can be found at git hub."
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} " -- Astade Developers <dev@astade.tigris.org>  $(date -R)"
echo >> ${CHANGELOG}

debuild -S

popd

exit 0

