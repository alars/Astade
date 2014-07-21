//~~ void printForwardDeclaration(unsigned int indent) [ACOperation] ~~
wxString value = wxS("operation");

if (m_Element->IsStatic())
    value = wxS("static ") + value;
value = m_Element->GetVisibility() + wxS(" ") + value;
if (m_Element->IsConst())
    value = wxS("const ") + value;
if (m_Element->IsDeprecated())
    value = wxS("deprecated ") + value;

printName(indent,value.mb_str().data(),m_Element,true);
printDescription(indent+1,m_Element);
printForwardDeclarations(indent);
pIndent(indent);
printf("}\n");
