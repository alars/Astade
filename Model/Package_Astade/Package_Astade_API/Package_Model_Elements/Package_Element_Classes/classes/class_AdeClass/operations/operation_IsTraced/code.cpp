wxConfigBase* theConfig = wxConfigBase::Get();
bool traced;
theConfig->Read(wxS("TreeView/TraceClasses/") + GetGUID(), &traced, false);
return traced;
