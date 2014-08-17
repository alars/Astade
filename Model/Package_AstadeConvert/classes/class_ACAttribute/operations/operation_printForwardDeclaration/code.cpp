//~~ void printForwardDeclaration(unsigned int indent) [ACAttribute] ~~
printName(indent,m_keyword.mb_str().data(),m_Element,true);
printDescription(indent+1,m_Element);

wxString value = m_Element->GetCodingType();

if (!value.empty())
{
    pIndent(indent+1);
    printf("type: \"%s\";\n",value.mb_str().data());
}

value = m_Element->GetBits();

if (!value.empty())
{
    pIndent(indent+1);
    printf("bits: \"%s\";\n",value.mb_str().data());
}

value = m_Element->GetDefault();

if (!value.empty())
{
    pIndent(indent+1);
    printf("default: \"%s\";\n",value.mb_str().data());
}

value = m_Element->GetConstraint();

if (!value.empty())
{
    pIndent(indent+1);
    printf("constraint: \"%s\";\n",value.mb_str().data());
}

pIndent(indent);
printf("}\n");
