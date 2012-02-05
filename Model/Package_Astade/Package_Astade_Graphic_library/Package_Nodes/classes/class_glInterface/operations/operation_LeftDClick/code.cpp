//~~ void LeftDClick() [glInterface] ~~

wxString aString = wxGetTextFromUser(wxEmptyString, wxS("Label"), myFloatingLabel.myText, myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace(wxS("\t"), wxS(" "));
aString.Replace(wxS("\n"), wxS(" "));
aString.Replace(wxS("  "), wxS(" "));
if (aString != myFloatingLabel.myText)
{
    myFloatingLabel.myText = aString;
    glChangeNotifier::Notify();
    myFloatingLabel.Refresh();
}
