wxMenu* aSubUp =  new wxMenu("delete:");

wxString aLabel = GetLabel();
aLabel.Replace("\n"," ");
aSubUp->Append(deleteID,wxString("Actor: ")+aLabel,wxEmptyString, wxITEM_NORMAL);

int count = 0;
for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
{
	aLabel = (*it)->GetEndNode().GetLabel();
	aLabel.Replace("\n"," ");
	aSubUp->Append(deleteAssiciationID+(count++),wxString("Association to: ")+aLabel,"", wxITEM_NORMAL);
}

count = 0;
for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	aLabel = (*it)->GetEndNode().GetLabel();
	aLabel.Replace("\n"," ");
	aSubUp->Append(deleteSpecialisationID+(count++),wxString("Specialisation of: ")+aLabel,"", wxITEM_NORMAL);
}

return aSubUp;