#!/bin/bash -e

BUILD=${1:-1}

DEBDIR=Source/Packages/deb

VERSION=`awk -F '"' '{print $2}' Model/components_WGNBOFKH/Component_Astade/manual/AstadeVersion.h`

ARCH=`uname -m`
if [ "${ARCH}" = "i686" ]; then
	ARCH=i386
elif [ "${ARCH}" = "i586" ]; then
	ARCH=i386
elif [ "${ARCH}" = "x86_64" ]; then
	ARCH=amd64
fi

rm -rf ${DEBDIR}/tmp
mkdir -p ${DEBDIR}/tmp/{DEBIAN,usr/bin}
sed -e s/VERSION-BUILD/${VERSION}-${BUILD}/ -e s/ARCH/${ARCH}/ \
	<${DEBDIR}/astadegraphlib_control >${DEBDIR}/tmp/DEBIAN/control

env prefix=`pwd`/${DEBDIR}/tmp/usr ./build_all.sh install

rm -rf ${DEBDIR}/tmp/usr/bin/

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp astadegraphlib-${VERSION}-${BUILD}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
