#!/bin/bash -e

BUILD=${1:-1}

DEBDIR=Source/Packages/deb
ICONDIR=Source/Icons
DESKTOPDIR=Source/freedesktop

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
mkdir -p ${DEBDIR}/tmp/{DEBIAN,usr/{bin,share/{pixmaps,applications}}}
sed -e s/VERSION-BUILD/${VERSION}-${BUILD}/ -e s/ARCH/${ARCH}/ \
	<${DEBDIR}/control >${DEBDIR}/tmp/DEBIAN/control

cp -p ${DESKTOPDIR}/Astade-Tree.png ${DEBDIR}/tmp/usr/share/pixmaps/
cp -p ${DESKTOPDIR}/Astade-Tree.desktop ${DEBDIR}/tmp/usr/share/applications/

env prefix=`pwd`/${DEBDIR}/tmp/usr ./build_all.sh install

rm -rf ${DEBDIR}/tmp/usr/include/
rm -rf ${DEBDIR}/tmp/usr/lib/
rm -f ${DEBDIR}/tmp/usr/bin/AstadeDraw
rm -f ${DEBDIR}/tmp/usr/bin/AstadeGenerate
rm -f ${DEBDIR}/tmp/usr/bin/{C,Cpp}Generator
rm -f ${DEBDIR}/tmp/usr/bin/StateChartCoder*
rm -f ${DEBDIR}/tmp/usr/bin/instrument
rm -f ${DEBDIR}/tmp/usr/bin/Trace2UML

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp astade-${VERSION}-${BUILD}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
