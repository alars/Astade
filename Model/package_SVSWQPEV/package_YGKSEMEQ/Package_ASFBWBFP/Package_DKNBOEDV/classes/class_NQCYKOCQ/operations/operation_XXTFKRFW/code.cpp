wxMenu* aSubUp =  new wxMenu("delete:");

aSubUp->Append(deleteID,wxString("Actor: ")+GetLabel(),wxEmptyString, wxITEM_NORMAL);
int count = 0;

for (std::set<GrafArrow*>::iterator it = myAssociation.begin(); it != myAssociation.end(); it++)
	aSubUp->Append(deleteAssiciationID+(count++),wxString("Association to: ")+(*it)->GetEndNode().GetLabel(),"", wxITEM_NORMAL);

return aSubUp;