//~~ void printDeclaration() [ACPackage] ~~
printf("\npackage[%s] {\n",m_Element->GetLabel().mb_str().data());
printForwardDeclarations(1);
printf("}\n");