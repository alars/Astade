int aID;
configObject.Read("ID",&aID);
SetNodeID(aID);
myLabel->SetValue(configObject.Read("Label"));