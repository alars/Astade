wxConfigBase* theConfig = wxConfigBase::Get();
bool traced;
theConfig->Read("TreeView/TraceClasses/"+GetGUID(),&traced,false);
return traced;
