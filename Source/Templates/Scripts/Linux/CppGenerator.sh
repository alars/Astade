#!/bin/sh --

echo "CppGenerator.sh $1 $2 $3" > ~/tmp/CppGenerator.log

TargetDir=`dirname $2`
TargetFile=`basename $2 | cut -d'.' -f1`
Target=${TargetDir}/${TargetFile}
Temp=/tmp/${TargetFile}

echo "CppGenerator $1 ${Temp}.c $3" >> ~/tmp/CppGenerator.log
CppGenerator $1 ${Temp}.c $3

if `diff -I ".*@date.*UTC.*" ${Temp}.cpp ${Target}.cpp`; then
	echo "rm ${Temp}.cpp" >> ~/tmp/CppGenerator.log
	rm ${Temp}.cpp
else
	echo "mv ${Temp}.cpp ${Target}.cpp" >> ~/tmp/CppGenerator.log
	mv ${Temp}.cpp ${Target}.cpp
fi
	
if `diff -I ".*@date.*UTC.*" ${Temp}.h ${Target}.h `; then
	echo "rm ${Temp}.h" >> ~/tmp/CppGenerator.log
	rm ${Temp}.h
else
	echo "mv ${Temp}.h ${Target}.h" >> ~/tmp/CppGenerator.log
	mv ${Temp}.h ${Target}.h
fi

exit 0
