//~~ void generateNode(wxConfigBase& config, const wxString& nodename) [CMain] ~~
std::cout << "\t" << nodename.utf8_str() << "[";

wxString ClassName = config.Read(wxS("ClassName"));

if (ClassName == wxS("usecase"))
    std::cout << "shape=oval, style=filled, fillcolor=grey, ";

if (ClassName == wxS("actor"))
    std::cout << "shape=pentagon, color=red, style=filled, fillcolor=grey, ";

if (ClassName == wxS("note"))
    std::cout << "shape=note, color=green, style=filled, fillcolor=grey, ";

if (ClassName == wxS("component"))
    std::cout << "shape=component, color=blue, ";

if (ClassName == wxS("activity"))
    std::cout << "shape=house, orientation=270, color=grey, style=filled, fillcolor=yellow, ";

if (ClassName == wxS("artefact"))
    std::cout << "shape=note, color=black, style=filled, fillcolor=blue, ";

if (ClassName == wxS("artefact"))
    std::cout << "shape=note, color=black, style=filled, fillcolor=blue, ";

if (ClassName == wxS("guidance"))
    std::cout << "shape=parallelogram, color=black, ";

wxString label = config.Read(wxS("Label"));
label.Replace(wxS("\""),wxS("\\\""));
std::cout << "label=\"" << optimizedString(label).utf8_str() << "\"]";

std::cout << ";" << std::endl;

generateGeneralisations(config,nodename);
generateExtend(config,nodename);
generateInclude(config,nodename);
generateAssociation(config,nodename);
generateAttach(config,nodename);
generateCUse(config,nodename);
generateIUse(config,nodename);
generateProvide(config,nodename);
generateCreate(config,nodename);
generateComposition(config,nodename);

