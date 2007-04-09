delete aFileMenu->Remove(ID_RECENT1);
delete aFileMenu->Remove(ID_RECENT2);
delete aFileMenu->Remove(ID_RECENT3);
delete aFileMenu->Remove(ID_RECENT4);

wxConfigBase* theConfig = wxConfigBase::Get();
wxString aString;

if (theConfig->Read("TreeView/Recent_1", &aString, wxEmptyString))
	aFileMenu->Append(ID_RECENT1, aString, "", wxITEM_NORMAL);

if (theConfig->Read("TreeView/Recent_2", &aString, wxEmptyString))
	aFileMenu->Append(ID_RECENT2, aString, "", wxITEM_NORMAL);

if (theConfig->Read("TreeView/Recent_3", &aString, wxEmptyString))
	aFileMenu->Append(ID_RECENT3, aString, "", wxITEM_NORMAL);

if (theConfig->Read("TreeView/Recent_4", &aString, wxEmptyString))
	aFileMenu->Append(ID_RECENT4, aString, "", wxITEM_NORMAL);