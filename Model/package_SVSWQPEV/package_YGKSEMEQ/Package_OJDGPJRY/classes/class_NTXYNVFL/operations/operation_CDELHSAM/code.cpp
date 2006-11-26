int i = 1;
wxString nodeName;
nodeName.Printf("Nodes/Node_%d",i);
while (config.Exists(nodeName))
{
	wxLogMessage(nodeName);
	nodeName += "/NodeType";
	if (config.Exists(nodeName))
	{
		wxString nodeType = config.Read(nodeName,"");
		wxObject* object = wxCreateDynamicObject(nodeType);
		if (object)
		{
		}
		else
		{
			wxLogError("\"%s\" cannot be created", nodeType.c_str());
		}
	}
	else
	{
		wxLogError("\"%s\" does not exist", nodeName.c_str());
	}
	nodeName.Printf("Nodes/Node_%d",++i);
}