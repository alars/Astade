//~~ void SetTabsize(wxCommandEvent& event) [AstadeFrame] ~~

long old = wxConfigBase::Get()->Read(wxS("TreeView/Tabsize"), 4);
long New = wxGetNumberFromUser(wxS("Select your tabsize"), wxS("Tabsize"), wxEmptyString, old, 0, 8);

if (New > 0)
	wxConfigBase::Get()->Write(wxS("TreeView/Tabsize"), New);
