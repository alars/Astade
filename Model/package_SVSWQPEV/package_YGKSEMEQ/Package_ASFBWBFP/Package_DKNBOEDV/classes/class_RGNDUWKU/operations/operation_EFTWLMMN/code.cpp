int aID;
configObject.Read("ID",&aID);
SetNodeID(aID);
myLabel->SetValue(configObject.Read("Label"));
configObject.Read("Pinned", &m_Pinned, false);