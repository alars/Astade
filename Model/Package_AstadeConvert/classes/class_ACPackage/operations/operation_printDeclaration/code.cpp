//~~ void printDeclaration() [ACPackage] ~~
printf("\npackage [");
printName(m_Element,true);
printf("] {\n");
printForwardDeclarations(1);
printf("}\n");
printDeclarations();