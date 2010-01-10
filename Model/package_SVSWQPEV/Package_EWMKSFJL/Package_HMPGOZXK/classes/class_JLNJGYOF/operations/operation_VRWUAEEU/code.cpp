wxString aString = wxGetTextFromUser("","End point multiplicity",myEndMult.myText,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t","");
aString.Replace("\n","");
aString.Replace(" ","");
if (aString != myEndMult.myText)
{
    myEndMult.myText = aString;    
    Refresh();
}