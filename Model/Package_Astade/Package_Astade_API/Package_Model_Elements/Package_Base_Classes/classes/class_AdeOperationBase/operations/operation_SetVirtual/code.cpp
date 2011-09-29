//~~ void SetVirtual(bool value) [AdeOperationBase] ~~
Reload();

if (value)
    myConfig->Write(wxS("Astade/Virtual"), wxS("yes"));
else
    myConfig->Write(wxS("Astade/Virtual"), wxS("no"));
    
myConfig->Flush();