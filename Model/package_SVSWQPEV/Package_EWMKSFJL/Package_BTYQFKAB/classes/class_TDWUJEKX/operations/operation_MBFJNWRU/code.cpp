myLabel = wxGetTextFromUser("","Label",myLabel,myParent);
myLabel.Replace("\t"," ");
myLabel.Replace("\n"," ");
myLabel.Replace("  "," ");
myLabel.Trim(false);
myLabel.Trim(true);
myParent->Refresh();
