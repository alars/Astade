//~~ void printForwardDeclaration(unsigned int indent) [ACParameter] ~~
printName(indent,"parameter",m_Element,false);
printDescription(indent+1,m_Element);

wxString value = m_Element->GetCodingType();

if (!value.empty())
{
    pIndent(indent+1);
    printf("type: \"%s\";\n",value.mb_str().data());
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
