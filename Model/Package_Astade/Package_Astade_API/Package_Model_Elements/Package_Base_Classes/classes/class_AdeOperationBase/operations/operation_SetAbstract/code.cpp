//~~ void SetAbstract(bool value) [AdeOperationBase] ~~
Reload();

if (value)
    myConfig->Write(wxS("Astade/Abstract"), wxS("yes"));
else
    myConfig->Write(wxS("Astade/Abstract"), wxS("no"));
  
myConfig->Flush();