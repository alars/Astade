//~~ void Load(wxConfigBase& configObject) [glInterface] ~~

int x,y;
configObject.Read(wxS("LabelPosX"), &x);
configObject.Read(wxS("LabelPosY"), &y);

myFloatingLabel.AddPosition(glVector(x, y - 17));

configObject.Read(wxS("Label"), &myFloatingLabel.myText);
myFloatingLabel.myText.Trim(false);
myFloatingLabel.myText.Trim(true);
myFloatingLabel.myText.Replace(wxS("\t"), wxS(" "));
myFloatingLabel.myText.Replace(wxS("\n"), wxS(" "));
myFloatingLabel.myText.Replace(wxS("  "), wxS(" "));

glNode::Load(configObject);
