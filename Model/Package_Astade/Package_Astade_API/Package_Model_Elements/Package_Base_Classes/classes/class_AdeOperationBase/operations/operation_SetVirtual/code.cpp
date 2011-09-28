//~~ void SetVirtual(bool value) [AdeOperationBase] ~~
if (value)
	myConfig->Write(wxS("Astade/Virtual"), wxS("yes"));
else
	myConfig->Write(wxS("Astade/Virtual"), wxS("no"));
