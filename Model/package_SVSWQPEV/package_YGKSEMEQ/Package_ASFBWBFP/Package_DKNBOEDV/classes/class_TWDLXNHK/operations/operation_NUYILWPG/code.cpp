while (!myGrafNodes.empty())
{
	delete *myGrafNodes.begin();
	myGrafNodes.erase(myGrafNodes.begin());
}

configObject.SetPath("/Window");

int w = 300;
configObject.Read("XSize",&w);

int h = 200;
configObject.Read("YSize",&h);

GetParent()->SetSize(w,h);

int count = 1;
wxString nodeName;
nodeName.Printf("/Nodes/Node%03d",count);

while (configObject.Exists(nodeName))
{
	configObject.SetPath(nodeName);
	GrafNode* aGrafNode = GrafNodeRegister::GetInstance().Create(configObject,this);
	if (aGrafNode)
		aGrafNode->Load(configObject);
	count++;
	nodeName.Printf("/Nodes/Node%03d",count);
}
