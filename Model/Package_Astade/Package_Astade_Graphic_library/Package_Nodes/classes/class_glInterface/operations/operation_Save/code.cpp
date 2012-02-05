//~~ void Save(wxConfigBase& configObject) [glInterface] ~~

glNode::Save(configObject);
configObject.Write(wxS("Label"), myFloatingLabel.myText);
configObject.Write(wxS("ClassName"), wxS("interface"));

glVector lpos = myFloatingLabel.absGetDrawPosition() - absGetDrawPosition();

configObject.Write(wxS("LabelPosX"), lpos.xCoord());
configObject.Write(wxS("LabelPosY"), lpos.yCoord());
