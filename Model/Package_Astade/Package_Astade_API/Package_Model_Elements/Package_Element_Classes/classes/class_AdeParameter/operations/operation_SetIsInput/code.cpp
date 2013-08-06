//~~ void SetIsInput(bool value) [AdeParameter] ~~
if (value)
    myConfig->Write(wxS("Astade/InputParameter"), wxS("yes"));
else
    myConfig->Write(wxS("Astade/InputParameter"), wxS("no"));

myConfig->Flush();
