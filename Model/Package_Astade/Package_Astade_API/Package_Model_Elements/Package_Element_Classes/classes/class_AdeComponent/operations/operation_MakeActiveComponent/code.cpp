wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Write(wxS("TreeView/ActiveComponent"), GetFileName().GetFullPath());
theConfig->Write(wxS("TreeView/ActiveGUID"), GetGUID());
theConfig->Flush();
