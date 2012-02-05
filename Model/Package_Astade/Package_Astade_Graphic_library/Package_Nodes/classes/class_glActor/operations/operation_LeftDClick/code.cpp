//~~ void LeftDClick() [glActor] ~~

wxString aString = wxGetTextFromUser(wxEmptyString, wxS("Label"), myLabel, myParent);
aString.Trim(false);
aString.Trim(true);
aString.Replace(wxS("\t"), wxS(" "));
aString.Replace(wxS("\n"), wxS(" "));
aString.Replace(wxS("  "), wxS(" "));
if (aString != myLabel)
{
    myLabel = aString;
    glChangeNotifier::Notify();
    Refresh();
}
