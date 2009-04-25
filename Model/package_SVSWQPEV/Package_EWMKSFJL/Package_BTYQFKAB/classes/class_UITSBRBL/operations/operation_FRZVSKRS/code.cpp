myLabel = wxGetTextFromUser("","Label",myLabel,myParent);
myLabel.Trim(false);
myLabel.Trim(true);
myLabel.Replace("  "," ");
myLabel.Replace("\t","");
myLabel.Replace("\n","");
Refresh();
