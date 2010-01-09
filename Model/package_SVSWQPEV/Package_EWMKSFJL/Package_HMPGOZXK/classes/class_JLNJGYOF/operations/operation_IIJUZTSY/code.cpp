wxString aString = wxGetTextFromUser("","Start point multiplicity",myStartMult,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t","");
aString.Replace("\n","");
aString.Replace(" ","");
if (aString != myStartMult)
{
    myStartMult = aString;
    Refresh();
}