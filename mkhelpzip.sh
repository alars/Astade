#!/bin/bash -e

cd www/HTMLHelp
rm -f help.zip
zip -r help.zip . -i@mkhelpzip.inc
