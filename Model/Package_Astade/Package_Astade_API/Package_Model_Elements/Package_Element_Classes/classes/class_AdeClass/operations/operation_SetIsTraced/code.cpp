wxConfigBase* theConfig = wxConfigBase::Get();

if (trace)
    theConfig->Write(wxS("TreeView/TraceClasses/") + GetGUID(), true);
else
    theConfig->DeleteEntry(wxS("TreeView/TraceClasses/") + GetGUID());

theConfig->Flush();
