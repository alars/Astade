#!/bin/bash -e

BUILD=${1:-1}

DEBDIR=Source/Packages/deb
ICONDIR=Source/Icons
DESKTOPDIR=Source/freedesktop

VERSION=`awk -F '"' '{print $2}' Model/Components_Trace2UML_components/Component_Trace2UML/manual/Trace2UMLVersion.h`

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
	<${DEBDIR}/trace2uml_control >${DEBDIR}/tmp/DEBIAN/control

cp -p ${DESKTOPDIR}/Astade-Trace.png ${DEBDIR}/tmp/usr/share/pixmaps/
cp -p ${DESKTOPDIR}/Astade-Trace.desktop ${DEBDIR}/tmp/usr/share/applications/
cp -p Model/Components_Trace2UML_components/Component_instrument/Config_Linux/instrument ${DEBDIR}/tmp/usr/bin/
cp -p Model/Components_Trace2UML_components/Component_Trace2UML/Config_Linux_Debug/Trace2UML ${DEBDIR}/tmp/usr/bin/

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp trace2uml-${VERSION}-${BUILD}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
