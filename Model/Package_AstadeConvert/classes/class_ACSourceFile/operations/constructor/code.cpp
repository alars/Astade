//~~ ACSourceFile(AdeSourceFile* element) [ACSourceFile] ~~
if (m_Element->GetName() == wxS("prolog.h"))
    m_keyword = "spectification prolog";
    
if (m_Element->GetName() == wxS("prolog.c"))
    m_keyword = "implementation prolog";
    
if (m_Element->GetName() == wxS("prolog.cpp"))
    m_keyword = "implementation prolog";
    
if (m_Element->GetName() == wxS("epilog.h"))
    m_keyword = "spectification epilog";
    
if (m_Element->GetName() == wxS("epilog.c"))
    m_keyword = "implementation epilog";
    
if (m_Element->GetName() == wxS("epilog.cpp"))
    m_keyword = "implementation epilog";
    
 if (m_Element->GetName() == wxS("code.cpp"))
    m_keyword = "action";
    
 if (m_Element->GetName() == wxS("code.c"))
    m_keyword = "action";
    

