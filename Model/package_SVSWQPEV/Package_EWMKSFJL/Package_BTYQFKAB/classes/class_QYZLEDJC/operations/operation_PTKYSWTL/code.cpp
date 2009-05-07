configObject.Read("Label",&myFloatingLabel.myText);
myFloatingLabel.myText.Trim(false);
myFloatingLabel.myText.Trim(true);
myFloatingLabel.myText.Replace("\t"," ");
myFloatingLabel.myText.Replace("\n"," ");
myFloatingLabel.myText.Replace("  "," ");

glNode::Load(configObject);
