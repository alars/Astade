#!/bin/bash --
#
#

DIRNAME=$(dirname $0)
CHANGELOG="debian/changelog"

# include version info
source version

# include command line options
source ${DIRNAME}/getopts.sh

# clean up
rm -rf astade-${VERSION}
rm -f  astade_${VERSION}.orig.tar.gz

# unpack and prepare
tar xzf astade_${VERSION}.tar.gz
ln -s astade_${VERSION}.tar.gz astade_${VERSION}.orig.tar.gz
cp -r Source/Packages/ubuntu/${DIST}/debian astade-${VERSION}/

pushd astade-${VERSION}

# create changelog
echo  > ${CHANGELOG} "astade (${VERSION}-0ubuntu${PATCHLEVEL}~${DIST}) ${DIST}; urgency=low"
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} "  * The full changelog can be found at GitHub."
echo >> ${CHANGELOG}
echo >> ${CHANGELOG} " -- ${CHANGELOG_NAME} <${CHANGELOG_EMAIL}>  $(date -R)"
echo >> ${CHANGELOG}

# build source package
debuild -S -d

popd

exit 0
