//~~ void Load(wxConfigBase& configObject) [glFloatingItem] ~~

long x, y;
configObject.Read(wxS("xPos"), &x);
configObject.Read(wxS("yPos"), &y);
absPosition = glVector(x, y);
