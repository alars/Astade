wxConfigBase* theConfig = wxConfigBase::Get();
theConfig->Write("TreeView/ActiveComponent",GetFileName().GetFullPath());
theConfig->Write("TreeView/ActiveGUID",GetGUID());
theConfig->Flush();