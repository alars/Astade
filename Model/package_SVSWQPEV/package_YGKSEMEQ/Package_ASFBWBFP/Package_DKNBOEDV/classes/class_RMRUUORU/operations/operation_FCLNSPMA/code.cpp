wxMenu* aSubUp =  new wxMenu("delete:");

aSubUp->Append(deleteID,wxString("Use case: ")+GetLabel(),wxEmptyString, wxITEM_NORMAL);
int count = 0;

for (std::set<GrafArrow>::iterator it = mySuperclass.begin(); it != mySuperclass.end(); it++)
	aSubUp->Append(deleteSpecialisationID+(count++),wxString("Specialisation of: ")+(*it).GetEndNode().GetLabel(),"", wxITEM_NORMAL);

count = 0;
for (std::set<GrafArrow>::iterator it = myExtend.begin(); it != myExtend.end(); it++)
	aSubUp->Append(deleteExtentionID+(count++),wxString("Extention of: ")+(*it).GetEndNode().GetLabel(),"", wxITEM_NORMAL);

count = 0;
for (std::set<GrafArrow>::iterator it = myInclude.begin(); it != myInclude.end(); it++)
	aSubUp->Append(deleteIncludeID+(count++),wxString("Include of: ")+(*it).GetEndNode().GetLabel(),"", wxITEM_NORMAL);

return aSubUp;