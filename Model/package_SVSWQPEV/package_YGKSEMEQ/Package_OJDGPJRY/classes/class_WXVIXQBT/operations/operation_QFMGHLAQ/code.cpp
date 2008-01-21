wxString nodeName;
nodeName.Printf("Node_%p", this);
config.SetPath(nodeName);

config.Write("nodeType",GetClassInfo()->GetClassName());
