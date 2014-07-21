//~~ void printForwardDeclaration(unsigned int indent) [ACUnknown] ~~
if (m_Element->GetLabel() == wxS("auto"))
    return;

if (m_Element->GetLabel() == wxS("manual"))
    return;

if (m_Element->GetLabel() == wxS("Jamfile"))
    return;

if (m_Element->GetLabel() == wxS("Doxyfile"))
    return;
    
if (m_Element->GetLabel() == wxS("Doxyfile.dox"))
    return;
    
if (m_Element->GetLabel() == wxS("Makefile"))
    return;

if (m_Element->GetLabel() == wxS("usecase diagrams"))
    return;

if (m_Element->GetLabel().EndsWith(wxS(".o")))
    return;

pIndent(indent);
printf("// unknown %s\n",m_Element->GetLabel().mb_str().data());
