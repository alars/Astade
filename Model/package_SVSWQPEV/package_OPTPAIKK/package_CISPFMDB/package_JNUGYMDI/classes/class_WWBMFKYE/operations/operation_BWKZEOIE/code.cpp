wxConfigBase* theConfig = wxConfigBase::Get();

if (trace)
    theConfig->Write("TreeView/TraceClasses/"+GetGUID(),true);
else
    theConfig->DeleteEntry("TreeView/TraceClasses/"+GetGUID());
