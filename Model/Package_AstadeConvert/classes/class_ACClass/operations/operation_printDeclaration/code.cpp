//~~ void printDeclaration() [ACClass] ~~
printf("\nclass [");
printName(m_Element,true);
printf("] {\n");
printDescription(1,m_Element);
printForwardDeclarations(0);
printf("}\n");
printDeclarations();