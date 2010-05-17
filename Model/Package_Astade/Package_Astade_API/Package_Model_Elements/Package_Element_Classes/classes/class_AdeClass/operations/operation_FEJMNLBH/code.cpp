//~~ bool IsManualClass() [AdeClass] ~~
bool isManual = false;
myConfig->Read(wxS("Astade/ManualClass"), &isManual);
return isManual;
