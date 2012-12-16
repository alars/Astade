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

tar xzf astade_${VERSION}-${DATE}.tar.gz
ln -s astade_${VERSION}-${DATE}.tar.gz astade_${VERSION}-${DATE}.orig.tar.gz
cp -r Source/Packages/ubuntu/${DIST}/debian astade-${VERSION}-${DATE}/

pushd astade-${VERSION}-${DATE}

echo  > ${CHANGELOG} "astade (${VERSION}-${DATE}-0ubuntu1${SUFFIX}) ${DIST}; urgency=low"
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} "  * The full changelog can be found at git hub."
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} " -- Astade Buildserver <buildserver@astade.tigris.org>  $(date -R)"
echo >> ${CHANGELOG}

debuild -S

popd

exit 0

