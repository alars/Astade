//~~ void printForwardDeclaration(unsigned int indent) [ACDestructor] ~~

wxString value = wxS("destructor");
if (m_Element->IsInline())
    value = wxS("inline ") + value;

if (m_Element->IsDeprecated())
    value = wxS("deprecated ") + value;

if (m_Element->IsVirtual())
    value = wxS("virtual ") + value;

printf("\n");
pIndent(indent);
printf("%s {\n", value.mb_str().data());

printDescription(indent+1,m_Element);

printForwardDeclarations(indent);
pIndent(indent);
printf("}\n");
