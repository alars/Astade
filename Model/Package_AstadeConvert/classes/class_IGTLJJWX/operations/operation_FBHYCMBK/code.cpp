//~~ void printForwardDeclaration(unsigned int indent) [ACAttribute] ~~
printName(indent,m_keyword,m_Element,true);
printDescription(indent+1,m_Element);
pIndent(indent);
printf("}\n");
