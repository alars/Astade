wxString aString = wxGetTextFromUser("","End point multiplicity",myEndMult,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t","");
aString.Replace("\n","");
aString.Replace(" ","");
if (aString != myEndMult)
{
    myEndMult = aString;    
    Refresh();
}