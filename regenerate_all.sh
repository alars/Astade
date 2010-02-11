#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
AstadeGenerate -X -c Components_Trace2UML_components/Component_Trace2UML/
echo "**********************************"
echo "	instrument"
echo "**********************************"
AstadeGenerate -X -c Components_Trace2UML_components/Component_instrument/
