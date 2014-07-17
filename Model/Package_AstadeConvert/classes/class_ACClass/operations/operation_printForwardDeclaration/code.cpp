//~~ void printForwardDeclaration(unsigned int indent) [ACClass] ~~
pIndent(indent);
printf("%s [",m_keyword);
printName(m_Element,false);
printf("];\n");
