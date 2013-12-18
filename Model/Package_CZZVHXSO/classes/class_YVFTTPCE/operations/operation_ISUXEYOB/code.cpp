//~~ void generateComposition(wxConfigBase& config, const wxString& nodename) [CMain] ~~
uint num = 1;
wxString name;
name.Printf(wxS("ArtefactComposition%03d"),num);

while (config.Exists(name))
{
    int dest;
    config.Read(name,&dest,0);
    if (dest > 0)
    {
        wxString destname;
        destname.Printf(wxS("Node%03d"),dest);
        std::cout << "\t" << nodename.utf8_str() << " -> " << destname.utf8_str() << "[";
        std::cout << "dir=both, arrowtail=odiamond, arrowhead=none, color=black";
        std::cout << "];" << std::endl;
    }
    num++;
    name.Printf(wxS("ArtefactComposition%03d"),num);
}
