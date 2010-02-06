wxConfigBase* theConfig = wxConfigBase::Get();
wxString activeGUID = theConfig->Read("TreeView/ActiveGUID");

return (activeGUID == GetGUID());