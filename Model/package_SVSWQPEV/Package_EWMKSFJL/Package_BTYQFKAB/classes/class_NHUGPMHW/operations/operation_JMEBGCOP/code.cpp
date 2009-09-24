wxString aString = wxGetTextFromUser("","Label",myLabel,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t"," ");
aString.Replace("\n"," ");
aString.Replace("  "," ");
if (aString != myLabel)
{
    myLabel = aString;
    Refresh();
}
