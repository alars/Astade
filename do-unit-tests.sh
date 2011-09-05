#!/bin/bash -e

cd Model

ASTADEGENERATE="Components_Astade_components/Component_AstadeGenerate/Config_Linux_Release/AstadeGenerate -C Components_Astade_components/Component_CppGenerator/Config_Linux_Debug/CppGenerator -a Components_Astade_components/Component_CGenerator/Config_Linux_Debug/CGenerator"

echo "**********************************"
echo "	generate ACF_test"
echo "**********************************"
${ASTADEGENERATE} -S Components_Astade_components/Component_StateChartCoderACF/Config_Linux_Debug/StateChartCoder -X -c Components_Astade_Unit_Tests/Component_ACF_test/
echo "**********************************"
echo "	build ACF_test"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_ACF_test/Config_Linux/ TARGET=ACF_test $1
echo "**********************************"
echo "	generate ACF_test++"
echo "**********************************"
${ASTADEGENERATE} -S Components_Astade_components/Component_StateChartCoderACF++/Config_Linux_Debug/StateChartCoder -X -c Components_Astade_Unit_Tests/Component_ACF_test++/
echo "**********************************"
echo "	build ACF_test++"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_ACF_test++/Config_Linux/ TARGET=ACF_test++ $1
echo "**********************************"
echo "	generate crossroad"
echo "**********************************"
${ASTADEGENERATE} -S Components_Astade_components/Component_StateChartCoderACF++/Config_Linux_Debug/StateChartCoder -X -c Components_Astade_Unit_Tests/Component_crossroad/
echo "**********************************"
echo "	build crossroad"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_crossroad/Config_Linux/ TARGET=crossroad $1
echo "**********************************"
echo "	generate ACF_Multithread"
echo "**********************************"
${ASTADEGENERATE} -S Components_Astade_components/Component_StateChartCoderACF++/Config_Linux_Debug/StateChartCoder -X -c Components_Astade_Unit_Tests/Component_ACF_Multithread/
echo "**********************************"
echo "	build ACF_Multithread"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_ACF_Multithread/Config_Linux/ TARGET=ACF_Multithread $1
echo "**********************************"
echo "	generate GraphicDrawer"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_Astade_Unit_Tests/Component_GraphicDrawer/
echo "**********************************"
echo "	build GraphicDrawer"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_GraphicDrawer/Config_Linux_Debug/ TARGET=GraphicDrawer $1
echo "**********************************"
echo "	generate HalloC"
echo "**********************************"
${ASTADEGENERATE} -S Components_Astade_components/Component_StateChartCoderC/Config_Linux_Debug/StateChartCoder -X -c Components_Astade_Unit_Tests/Component_HalloC/
echo "**********************************"
echo "	build HalloC"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_HalloC/Config_Linux/ TARGET=HalloC $1
echo "**********************************"
echo "	generate ReverseEngineer"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_Astade_Unit_Tests/Component_ReverseEngineer/
echo "**********************************"
echo "	build ReverseEngineer"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_ReverseEngineer/Config_Linux/ TARGET=ReverseEngineer $1
echo "**********************************"
echo "	generate RevisionControl"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_Astade_Unit_Tests/Component_RevisionControl/
echo "**********************************"
echo "	build RevisionControl"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_RevisionControl/Config_Linux_Debug/ TARGET=RevisionControl $1
echo "**********************************"
echo "	generate social"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_Astade_Unit_Tests/Component_social/
echo "**********************************"
echo "	build social"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_social/Config_Linux_Debug/ TARGET=social $1
echo "**********************************"
echo "	generate Staircase"
echo "**********************************"
${ASTADEGENERATE} -S Components_Astade_components/Component_StateChartCoderWx/Config_Linux_Debug/StateChartCoder -X -c Components_Astade_Unit_Tests/Component_Staircase/
echo "**********************************"
echo "	build Staircase"
echo "**********************************"
make -j 2 -C Components_Astade_Unit_Tests/Component_Staircase/Config_Linux_Release/ TARGET=Staircase $1
