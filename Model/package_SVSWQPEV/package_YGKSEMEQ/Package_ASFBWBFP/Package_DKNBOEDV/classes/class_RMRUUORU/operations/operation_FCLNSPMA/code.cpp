wxMenu* aSubUp =  new wxMenu("delete:");

wxString aLabel = GetLabel();
aLabel.Replace("\n"," ");
aSubUp->Append(deleteID,wxString("Use case: ")+aLabel,wxEmptyString, wxITEM_NORMAL);
int count = 0;

for (std::set<GrafArrow*>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
{
	aLabel = (*it)->GetEndNode().GetLabel();
	aLabel.Replace("\n"," ");
	aSubUp->Append(deleteSpecialisationID+(count++),wxString("Specialisation of: ")+aLabel,"", wxITEM_NORMAL);
}

count = 0;
for (std::set<GrafArrow*>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
{
	aLabel = (*it)->GetEndNode().GetLabel();
	aLabel.Replace("\n"," ");
	aSubUp->Append(deleteExtentionID+(count++),wxString("Extention of: ")+aLabel,"", wxITEM_NORMAL);
}

count = 0;
for (std::set<GrafArrow*>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
{
	aLabel = (*it)->GetEndNode().GetLabel();
	aLabel.Replace("\n"," ");
	aSubUp->Append(deleteIncludeID+(count++),wxString("Include of: ")+aLabel,"", wxITEM_NORMAL);
}

return aSubUp;