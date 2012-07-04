//~~ scPerson(glGraphicPanel* parent, long x, long y) [scPerson] ~~

Refresh();
AddMenuSeparator();
AddMenuFunction(wxS("Relation to ..."), wxCommandEventHandler(scPerson::OnCreateEdge));
AddMenuSeparator();
AddMenuFunction(wxS("set male"), wxCommandEventHandler(scPerson::SetMale));
AddMenuFunction(wxS("set female"), wxCommandEventHandler(scPerson::SetFemale));
AddMenuFunction(wxS("set child"), wxCommandEventHandler(scPerson::SetChild));
AddMenuFunction(wxS("set adult"), wxCommandEventHandler(scPerson::SetAdult));

