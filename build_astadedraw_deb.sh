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
mkdir -p ${DEBDIR}/tmp/{DEBIAN,usr/{bin,share/{Astade,doc/astade,pixmaps,applications}}}
sed -e s/VERSION-BUILD/${VERSION}-${BUILD}/ -e s/ARCH/${ARCH}/ \
	<${DEBDIR}/astadedraw_control >${DEBDIR}/tmp/DEBIAN/control

cp -p ${DESKTOPDIR}/Astade-Draw.png ${DEBDIR}/tmp/usr/share/pixmaps/
cp -p ${DESKTOPDIR}/Astade-Draw.desktop ${DEBDIR}/tmp/usr/share/applications/
cp -p ${DESKTOPDIR}/Astade-Draw.mime.xml ${DEBDIR}/tmp/usr/share/Astade/
cp -p ${DEBDIR}/preinst ${DEBDIR}/tmp/DEBIAN/
cp -p ${DEBDIR}/postinst ${DEBDIR}/tmp/DEBIAN/
cp -p ${DEBDIR}/prerm ${DEBDIR}/tmp/DEBIAN/
cp -p ${DEBDIR}/postrm ${DEBDIR}/tmp/DEBIAN/

cp Model/components_WGNBOFKH/Component_AstadeDraw/Config_Linux_Debug/AstadeDraw ${DEBDIR}/tmp/usr/bin/

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp astadedraw-${VERSION}-${BUILD}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
