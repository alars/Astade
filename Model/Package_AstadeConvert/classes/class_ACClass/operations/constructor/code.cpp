//~~ ACClass(AdeClass* element) [ACClass] ~~
if (element->IsLibClass())
    m_keyword = "libclass";
else if (element->IsManualClass())
    m_keyword = "manualclass";