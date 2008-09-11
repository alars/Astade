#!/bin/bash -e

BUILD=${1:-1}

DEBDIR=Source/Packages/deb
VERSION=`awk -F '"' '{print $2}' Model/components_WGNBOFKH/component_KSEQOEET/manual/AstadeVersion.h`

ARCH=`uname -m`
if [ "${ARCH}" = "i686" ]; then
	ARCH=i386
elif [ "${ARCH}" = "x86_64" ]; then
	ARCH=amd64
fi

rm -rf ${DEBDIR}/tmp
mkdir -p ${DEBDIR}/tmp/{DEBIAN,usr/{bin,share/Astade,share/doc/astade}}
sed -e s/VERSION-BUILD/${VERSION}-${BUILD}/ -e s/ARCH/${ARCH}/ \
	<${DEBDIR}/control >${DEBDIR}/tmp/DEBIAN/control

cp -p ${DEBDIR}/copyright ${DEBDIR}/tmp/usr/share/doc/astade/

./mkhelpzip.sh
cp -p www/HTMLHelp/help.zip ${DEBDIR}/tmp/usr/share/Astade/

env prefix=`pwd`/${DEBDIR}/tmp/usr ./build_all.sh install

pushd Source >/dev/null
find Templates -name .svn -prune -o -type f -exec rsync -av --relative {} Packages/deb/tmp/usr/share/Astade/ \;
popd >/dev/null

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp astade-${VERSION}-${BUILD}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
