//~~ bool IsLibClass() [AdeClass] ~~
bool isLib = false;
myConfig->Read(wxS("Astade/LibClass"), &isLib);
return isLib;
