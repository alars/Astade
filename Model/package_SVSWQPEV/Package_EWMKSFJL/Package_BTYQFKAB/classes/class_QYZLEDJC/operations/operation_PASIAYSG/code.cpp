wxString aString = wxGetTextFromUser("","Label",myFloatingLabel.myText,myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace("\t"," ");
aString.Replace("\n"," ");
aString.Replace("  "," ");
if (aString != myFloatingLabel.myText)
{
    myFloatingLabel.myText = aString;
    glChangeNotifier::Notify();
    myFloatingLabel.Refresh();
}
