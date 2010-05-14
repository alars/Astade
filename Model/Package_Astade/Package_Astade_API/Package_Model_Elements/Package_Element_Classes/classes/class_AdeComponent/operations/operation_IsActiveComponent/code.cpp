wxConfigBase* theConfig = wxConfigBase::Get();
wxString activeGUID = theConfig->Read(wxS("TreeView/ActiveGUID"));

return (activeGUID == GetGUID());
