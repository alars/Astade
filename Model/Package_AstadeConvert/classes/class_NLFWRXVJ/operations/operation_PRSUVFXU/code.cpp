//~~ void printForwardDeclaration(unsigned int indent) [ACOperation] ~~
wxString value = wxS("operation");

if (m_Element->IsStatic())
    value = wxS("static ") + value;
value = m_Element->GetVisibility() + wxS(" ") + value;

if (m_Element->IsAbstract())
    value = wxS("abstract ") + value;
else if (m_Element->IsVirtual())
    value = wxS("virtual ") + value;

if (m_Element->IsInline())
    value = wxS("inline ") + value;
if (m_Element->IsConst())
    value = wxS("const ") + value;
if (m_Element->IsDeprecated())
    value = wxS("deprecated ") + value;

printName(indent,value.mb_str().data(),m_Element,true);
printDescription(indent+1,m_Element);

value = m_Element->GetReturntype();

if (!value.empty())
{
    pIndent(indent+1);
    printf("type: \"%s\";\n",value.mb_str().data());
}

printForwardDeclarations(indent);
pIndent(indent);
printf("}\n");
