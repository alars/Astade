wxString aString = wxGetTextFromUser("","Label",myLabel.myText,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t"," ");
aString.Replace("\n"," ");
aString.Replace("  "," ");
if (aString != myLabel.myText)
{
    myLabel.myText = aString;
    Refresh();
}
