#!/bin/bash -e

cd Model

ASTADEGENERATE="components_WGNBOFKH/Component_XZAWFDAN/Config_ZUJGZNUN/AstadeGenerate -C components_WGNBOFKH/Component_CppGenerator/Config_PPWOWKVA/CppGenerator -a components_WGNBOFKH/Component_CGenerator/Linux_Debug/CGenerator"

echo "**********************************"
echo "	generate ACF_test"
echo "**********************************"
${ASTADEGENERATE} -S components_WGNBOFKH/Component_CBEUPFRX/Config_EAEBAKKD/StateChartCoder -X -c Components_UnitTests/Component_ACF_test/
echo "**********************************"
echo "	build ACF_test"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_ACF_test/Config_Linux/ TARGET=ACF_test $1
echo "**********************************"
echo "	generate ACF_test++"
echo "**********************************"
${ASTADEGENERATE} -S components_WGNBOFKH/Component_StateChartCoderACF++/Config_Linux_Debug/StateChartCoder -X -c Components_UnitTests/Component_ACF_test++/
echo "**********************************"
echo "	build ACF_test++"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_ACF_test++/Config_Linux/ TARGET=ACF_test++ $1
echo "**********************************"
echo "	generate GraphicDrawer"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_UnitTests/Component_GraphicDrawer/
echo "**********************************"
echo "	build GraphicDrawer"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_GraphicDrawer/Config_Linux_Debug/ TARGET=GraphicDrawer $1
echo "**********************************"
echo "	generate HalloC"
echo "**********************************"
${ASTADEGENERATE} -S components_WGNBOFKH/Component_FOGYFECV/Config_HEYGDBJI/StateChartCoder -X -c Components_UnitTests/Component_HalloC/
echo "**********************************"
echo "	build HalloC"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_HalloC/Config_Linux/ TARGET=HalloC $1
echo "**********************************"
echo "	generate ReverseEngineer"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_UnitTests/Component_ReverseEngineer/
echo "**********************************"
echo "	build ReverseEngineer"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_ReverseEngineer/Config_Linux/ TARGET=ReverseEngineer $1
echo "**********************************"
echo "	generate RevisionControl"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_UnitTests/Component_RevisionControl/
echo "**********************************"
echo "	build RevisionControl"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_RevisionControl/Config_Linux_Debug/ TARGET=RevisionControl $1
echo "**********************************"
echo "	generate social"
echo "**********************************"
${ASTADEGENERATE} -X -c Components_UnitTests/Component_social/
echo "**********************************"
echo "	build social"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_social/Config_Linux_Debug/ TARGET=social $1
echo "**********************************"
echo "	generate Staircase"
echo "**********************************"
${ASTADEGENERATE} -S components_WGNBOFKH/Component_StateChartCoderWx/Config_Linux_Debug/StateChartCoder -X -c Components_UnitTests/Component_Staircase/
echo "**********************************"
echo "	build Staircase"
echo "**********************************"
make -j 2 -C Components_UnitTests/Component_Staircase/Config_Linux_Release/ TARGET=Staircase $1
