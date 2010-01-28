wxString aString = wxGetTextFromUser("","Start point multiplicity",myStartMult.myText,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t","");
aString.Replace("\n","");
aString.Replace(" ","");
if (aString != myStartMult.myText)
{
    myStartMult.myText = aString;
    Refresh();
}