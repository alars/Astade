long old = wxConfigBase::Get()->Read("TreeView/Tabsize",4);
long New = wxGetNumberFromUser("Select your tabsize","Tabsize","",old,0,8);

if (New > 0)
	wxConfigBase::Get()->Write("TreeView/Tabsize",New);
