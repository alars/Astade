int i = 1;
wxString nodeName;
nodeName.Printf("Nodes/Node_%d",i);
while (config.Exists(nodeName))
{
	wxString nodeTypeKey = nodeName+"/NodeType";
	if (config.Exists(nodeTypeKey))
	{
		wxString nodeType = config.Read(nodeTypeKey,"");
		wxObject* object = wxCreateDynamicObject(nodeType);
		ACNode* aNode = dynamic_cast<ACNode*>(object);
		if (aNode)
		{
			config.SetPath(nodeName);
			aNode->Load(config);
			myNodes.insert(myNodes.begin(),aNode);
			wxLogError("\"%s\" successfully created", nodeType.c_str());
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