glNode::Save(configObject);
configObject.Write("Label",myFloatingLabel.myText);
configObject.Write("ClassName","interface");

glVector lpos = myFloatingLabel.absGetDrawPosition() - absGetDrawPosition();

configObject.Write("LabelPosX",lpos.xCoord());
configObject.Write("LabelPosY",lpos.yCoord());
