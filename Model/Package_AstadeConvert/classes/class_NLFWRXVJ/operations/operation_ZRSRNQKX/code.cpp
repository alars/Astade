//~~ void printDeclaration() [ACComponent] ~~
printName(0,"component",m_Element,true);
printDescription(1,m_Element);
pIndent(1);
printf("source path <%s/auto/>;\n",names(m_Element,wxS("/")).mb_str().data());
printForwardDeclarations(0);
printf("}\n");
printDeclarations();