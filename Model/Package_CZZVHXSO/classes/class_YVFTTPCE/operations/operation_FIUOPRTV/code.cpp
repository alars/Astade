//~~ void generateDot() [CMain] ~~
wxFileConfig aConfig(wxEmptyString, wxEmptyString, m_Filename, wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_RELATIVE_PATH);

std::cout << "digraph g{" << std::endl;
generateNodes(aConfig);
std::cout << "}" << std::endl;