//~~ void generateNode(wxConfigBase& config, const wxString& nodename) [CMain] ~~
std::cout << "\t" << nodename.utf8_str() << "[";

wxString ClassName = config.Read(wxS("ClassName"));

if (ClassName == wxS("usecase"))
    std::cout << "shape=oval, style=filled, fillcolor=grey, ";

wxString label = config.Read(wxS("Label"));
label.Replace(wxS("\""),wxS("\\\""));
std::cout << "label=\"" << label.utf8_str() << "\"]";

std::cout << ";" << std::endl;

generateGeneralisations(config,nodename);
