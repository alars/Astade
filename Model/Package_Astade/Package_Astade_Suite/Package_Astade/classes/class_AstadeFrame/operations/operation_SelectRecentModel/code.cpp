wxConfigBase* theConfig = wxConfigBase::Get();

wxString dir;

if (event.GetId() == ID_RECENT1)
	theConfig->Read("TreeView/Recent_1", &dir, wxEmptyString);

if (event.GetId() == ID_RECENT2)
	theConfig->Read("TreeView/Recent_2", &dir, wxEmptyString);

if (event.GetId() == ID_RECENT3)
	theConfig->Read("TreeView/Recent_3", &dir, wxEmptyString);

if (event.GetId() == ID_RECENT4)
	theConfig->Read("TreeView/Recent_4", &dir, wxEmptyString);

if (!dir.empty())
{
	wxFileName filename(dir);
	LoadModel(filename);
}
