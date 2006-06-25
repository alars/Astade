GrafNode::Save(configObject);

configObject.Write("ClassName","GrafUseCase");

int count = 0;
for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	wxString associationName;
	associationName.Printf("Extention%03d",++count);
	configObject.Write(associationName,(*it)->GetEndNode().GetNodeID());
}

count = 0;
for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	wxString associationName;
	associationName.Printf("Include%03d",++count);
	configObject.Write(associationName,(*it)->GetEndNode().GetNodeID());
}

count = 0;
for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	wxString associationName;
	associationName.Printf("Superclass%03d",++count);
	configObject.Write(associationName,(*it)->GetEndNode().GetNodeID());
}