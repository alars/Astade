#!/bin/bash -e

BUILD=${1:-1}

DEBDIR=Source/Packages/deb
ICONDIR=Source/Icons
DESKTOPDIR=Source/freedesktop

VERSION=`awk -F '"' '{print $2}' Model/components_WGNBOFKH/component_KSEQOEET/manual/AstadeVersion.h`

ARCH=`uname -m`
if [ "${ARCH}" = "i686" ]; then
	ARCH=i386
elif [ "${ARCH}" = "i586" ]; then
	ARCH=i386
elif [ "${ARCH}" = "x86_64" ]; then
	ARCH=amd64
fi

rm -rf ${DEBDIR}/tmp
mkdir -p ${DEBDIR}/tmp/{DEBIAN,usr/{bin,share/{Astade,doc/astade,pixmaps,applications}}}
sed -e s/VERSION-BUILD/${VERSION}-${BUILD}/ -e s/ARCH/${ARCH}/ \
	<${DEBDIR}/control >${DEBDIR}/tmp/DEBIAN/control

cp -p ${DESKTOPDIR}/Astade-Draw.png ${DEBDIR}/tmp/usr/share/pixmaps/
cp -p ${DESKTOPDIR}/Astade-Tree.png ${DEBDIR}/tmp/usr/share/pixmaps/
cp -p ${DESKTOPDIR}/Astade-Draw.desktop ${DEBDIR}/tmp/usr/share/applications/
cp -p ${DESKTOPDIR}/Astade-Tree.desktop ${DEBDIR}/tmp/usr/share/applications/
cp -p ${DESKTOPDIR}/Astade-Draw.mime.xml ${DEBDIR}/tmp/usr/share/Astade/
cp -p ${DEBDIR}/copyright ${DEBDIR}/tmp/usr/share/doc/astade/
cp -p ${DEBDIR}/preinst ${DEBDIR}/tmp/DEBIAN/
cp -p ${DEBDIR}/postinst ${DEBDIR}/tmp/DEBIAN/
cp -p ${DEBDIR}/prerm ${DEBDIR}/tmp/DEBIAN/
cp -p ${DEBDIR}/postrm ${DEBDIR}/tmp/DEBIAN/

./mkhelpzip.sh
cp -p www/HTMLHelp/help.zip ${DEBDIR}/tmp/usr/share/Astade/

env prefix=`pwd`/${DEBDIR}/tmp/usr ./build_all.sh install

rm -rf ${DEBDIR}/tmp/usr/include/
rm -rf ${DEBDIR}/tmp/usr/lib/
rm  ${DEBDIR}/tmp/usr/bin/Trace2UML

pushd Source >/dev/null
find Templates -name .svn -prune -o -type f -exec rsync -av --relative {} Packages/deb/tmp/usr/share/Astade/ \;
popd >/dev/null

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp astade-${VERSION}-${BUILD}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
