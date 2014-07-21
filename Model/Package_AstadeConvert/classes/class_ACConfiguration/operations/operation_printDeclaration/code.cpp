//~~ void printDeclaration() [ACConfiguration] ~~
printName(0,"configuration",m_Element,true);
printDescription(1,m_Element);
pIndent(1);
printf("Makefile <%s/Makefile>;\n",names(m_Element,wxS("/")).mb_str().data());
printForwardDeclarations(0);
printf("}\n");
printDeclarations();