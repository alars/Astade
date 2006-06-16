int w,h;
GetSize(&w,&h);

configObject.SetPath("/");
configObject.Write("Filetype","Saved file from Astade UseCaseEdit (www.Astade.Tigris.org)");
configObject.Write("SaveFileVersion",1);

configObject.SetPath("/Window");
configObject.Write("XSize",w);
configObject.Write("YSize",h);

configObject.DeleteGroup("/Nodes");

int count = 0;
for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	count++;
	(*it)->SetNodeID(count);
}

for (std::list<GrafNode*>::iterator it = myGrafNodes.begin(); it != myGrafNodes.end(); it++)
{
	wxString nodeName;
	nodeName.Printf("/Nodes/Node%03d",(*it)->GetNodeID());
	configObject.SetPath(nodeName);
	(*it)->Save(configObject);
}