//~~ wxMenu* CreatePrologEpilogMenu() [AstadeTreeItemBase] ~~

wxMenu* aSubUp =  new wxMenu(wxEmptyString);

aSubUp->Append(ID_EDITSPECPROLOG, wxS("edit specification prolog"), wxEmptyString, wxITEM_NORMAL);
aSubUp->Append(ID_EDITIMPPROLOG, wxS("edit implementation prolog"), wxEmptyString, wxITEM_NORMAL);
aSubUp->Append(ID_EDITSPECEPILOG, wxS("edit specification epilog"), wxEmptyString, wxITEM_NORMAL);
aSubUp->Append(ID_EDITIMPGEPILOG, wxS("edit implementation epilog"), wxEmptyString, wxITEM_NORMAL);

return aSubUp;
