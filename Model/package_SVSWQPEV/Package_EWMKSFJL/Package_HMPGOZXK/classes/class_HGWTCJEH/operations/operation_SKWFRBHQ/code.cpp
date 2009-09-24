wxString aLabel;

configObject.Read("Label",&aLabel);
aLabel.Trim(false);
aLabel.Trim(true);
aLabel.Replace("\t"," ");
aLabel.Replace("\n"," ");
aLabel.Replace("  "," ");

myLabel.myText = aLabel;
