GrafNode::Save(configObject);

configObject.Write("ClassName","GrafUseCase");

int count = 0;
for (std::set<GrafNode*>::iterator it = myExtent.begin(); it != myExtent.end(); it++)
{
	wxString associationName;
	associationName.Printf("Extention%03d",++count);
	configObject.Write(associationName,(*it)->GetNodeID());
}

count = 0;
for (std::set<GrafNode*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	wxString associationName;
	associationName.Printf("Include%03d",++count);
	configObject.Write(associationName,(*it)->GetNodeID());
}

count = 0;
for (std::set<GrafNode*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	wxString associationName;
	associationName.Printf("Superclass%03d",++count);
	configObject.Write(associationName,(*it)->GetNodeID());
}