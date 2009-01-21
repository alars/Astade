pushd www\HTMLHelp
del /f help.zip
zip -r help.zip . -i@mkhelpzip.inc
popd