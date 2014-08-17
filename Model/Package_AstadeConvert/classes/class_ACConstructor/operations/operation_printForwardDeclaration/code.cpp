//~~ void printForwardDeclaration(unsigned int indent) [ACConstructor] ~~
wxString value = wxS("constructor");

if (m_Element->IsInline())
    value = wxS("inline ") + value;

if (m_Element->IsExplicit())
    value = wxS("explicit ") + value;

if (m_Element->IsDeprecated())
    value = wxS("deprecated ") + value;

printf("\n");
pIndent(indent);
printf("%s {\n", value.mb_str().data());

printDescription(indent+1,m_Element);

value = m_Element->GetInitializers();

if (!value.empty())
{
    pIndent(indent+1);
    printf("initializer: \"%s\";\n",value.mb_str().data());
}

printForwardDeclarations(indent);
pIndent(indent);
printf("}\n");
