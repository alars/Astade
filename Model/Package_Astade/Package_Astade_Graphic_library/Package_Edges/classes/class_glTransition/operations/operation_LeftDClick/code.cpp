//~~ void LeftDClick() [glTransition] ~~

wxString aString = wxGetTextFromUser(wxEmptyString, wxS("Label"), myLabel.myText, myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace(wxS("\t"), wxS(" "));
aString.Replace(wxS("\n"), wxS(" "));
aString.Replace(wxS("  "), wxS(" "));
if (aString != myLabel.myText)
{
    myLabel.myText = aString;
    myLabel.Refresh();
}
