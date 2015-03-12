#!/bin/bash -e

BUILD=${1:-1}

DEBDIR=${PWD}/Source/Packages/deb

VERSION=`awk -F '"' '{print $2}' Model/Components_Astade_components/Component_Astade/manual/AstadeVersion.h`

ARCH=`uname -m`
if [ "${ARCH}" = "i686" ]; then
	ARCH=i386
elif [ "${ARCH}" = "i586" ]; then
	ARCH=i386
elif [ "${ARCH}" = "x86_64" ]; then
	ARCH=amd64
fi

rm -rf ${DEBDIR}/tmp
mkdir -p ${DEBDIR}/tmp/{DEBIAN,{etc,usr/{bin,share/{Astade,doc/astade}}}}
sed -e s/VERSION-BUILD/${VERSION}-${BUILD}/ -e s/ARCH/${ARCH}/ \
	<${DEBDIR}/astadetools_control >${DEBDIR}/tmp/DEBIAN/control
cp -p ${DEBDIR}/astadetools_conffiles ${DEBDIR}/tmp/DEBIAN/conffiles

cp -p ${DEBDIR}/copyright ${DEBDIR}/tmp/usr/share/doc/astade/

pushd Source >/dev/null
find Templates -name .svn -prune -o -type f -exec rsync -av --relative {} ${DEBDIR}/tmp/usr/share/Astade/ \;
popd >/dev/null
cp -p Source/Templates/Astade.ini ${DEBDIR}/tmp/etc/

cp Model/Components_Astade_components/Component_AstadeGenerate/Config_Linux_Release/AstadeGenerate ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_CGenerator/Config_Linux_Debug/CGenerator ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_CppGenerator/Config_Linux_Debug/CppGenerator ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_StateChartCoder/Config_Linux_Debug/StateChartCoder ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_StateChartCoderC/Config_Linux_Debug/StateChartCoderC ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Specials/Component_StateChartCoderVSM/Config_Linux_Debug/StateChartCoderVSM ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Specials/Component_StateChartCoderCdSys/Config_LinuxConfig/StateChartCoderCdSys ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_StateChartCoderACF/Config_Linux_Debug/StateChartCoderACF ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_StateChartCoderACF++/Config_Linux_Debug/StateChartCoderACF++ ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_StateChartCoderQt/Config_Linux_Debug/StateChartCoderQt ${DEBDIR}/tmp/usr/bin/
cp Model/Components_Astade_components/Component_StateChartCoderWx/Config_Linux_Debug/StateChartCoderWx ${DEBDIR}/tmp/usr/bin/
strip -s ${DEBDIR}/tmp/usr/bin/*

pushd ${DEBDIR} >/dev/null
fakeroot dpkg-deb --build tmp astadetools-${VERSION}-${BUILD}_${ARCH}.deb
popd >/dev/null

rm -rf ${DEBDIR}/tmp
