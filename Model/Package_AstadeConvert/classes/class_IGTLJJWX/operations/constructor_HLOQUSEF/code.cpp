//~~ ACAttribute(AdeAttribute* element) [ACAttribute] ~~
if (m_Element->IsStatic())
    m_keyword = wxS("static ") + m_keyword;
m_keyword = m_Element->GetVisibility() + wxS(" ") + m_keyword;
if (m_Element->IsConst())
    m_keyword = wxS("const ") + m_keyword;
if (m_Element->IsDeprecated())
    m_keyword = wxS("deprecated ") + m_keyword;
