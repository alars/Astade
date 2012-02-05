//~~ void Save(wxConfigBase& configObject) [glFloatingItem] ~~

configObject.Write(wxS("xPos"), absPosition.xCoord());
configObject.Write(wxS("yPos"), absPosition.yCoord());
