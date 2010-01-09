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

configObject.Read("StartMult",&myStartMult);
myStartMult.Trim(false);
myStartMult.Trim(true);
myStartMult.Replace("\t","");
myStartMult.Replace("\n","");
myStartMult.Replace(" ","");

configObject.Read("EndMult",&myEndMult);
myEndMult.Trim(false);
myEndMult.Trim(true);
myEndMult.Replace("\t","");
myEndMult.Replace("\n","");
myEndMult.Replace(" ","");
