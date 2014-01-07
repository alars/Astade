//~~ void generateNodes(wxConfigBase& config) [CMain] ~~
uint num = 1;
wxString name;
name.Printf(wxS("Node%03d"),num);

while (config.Exists(wxS("Nodes/")+name))
{
    config.SetPath(wxS("Nodes/")+name);
    generateNode(config, name);
    num++;
    name.Printf(wxS("Node%03d"),num);
    config.SetPath(wxS("/"));
}
