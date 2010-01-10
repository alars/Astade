wxString aLabel;
long aType;

configObject.Read("Type",&aType);
type = (relationType)aType;

configObject.Read("Label",&aLabel);
aLabel.Trim(false);
aLabel.Trim(true);
aLabel.Replace("\t"," ");
aLabel.Replace("\n"," ");
aLabel.Replace("  "," ");
myLabel.myText = aLabel;

configObject.Read("StartMult",&aLabel);
aLabel.Trim(false);
aLabel.Trim(true);
aLabel.Replace("\t","");
aLabel.Replace("\n","");
aLabel.Replace(" ","");
myStartMult.myText=aLabel;

configObject.Read("EndMult",&aLabel);
aLabel.Trim(false);
aLabel.Trim(true);
aLabel.Replace("\t","");
aLabel.Replace("\n","");
aLabel.Replace(" ","");
myEndMult.myText=aLabel;