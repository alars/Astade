wxString nodeName;
nodeName.Printf("Node_%08X",reinterpret_cast<unsigned int>(this));
config.SetPath(nodeName);

config.Write("nodeType",GetClassInfo()->GetClassName());