#!/bin/bash -e

cd Model
echo "**********************************"
echo "	Trace2UML"
echo "**********************************"
AstadeGenerate -X -c Components_LGPLTGDP/Component_TYWOOIDA/
echo "**********************************"
echo "	instrument"
echo "**********************************"
AstadeGenerate -X -c Components_LGPLTGDP/Component_instrument/
